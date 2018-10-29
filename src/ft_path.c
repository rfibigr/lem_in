/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:03:31 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/29 21:54:01 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	on entre les valeurs dans anthill START
	on parcourt le graphe en largeur
*/

int		ft_path(t_anthill *anthill, t_room **room)
{
	t_room	*start;
	t_room	*end;
	t_list	*list_of_path;

	list_of_path = NULL;
	start = anthill->start;
	end = anthill->end;
	anthill->nb_start_pipe = ft_tablen(start->connection);
	anthill->nb_end_pipe = ft_tablen(end->connection);

	while (ft_connection_use(end->connection))
	{
		ft_shortest_path(&start);
		ft_add_path(&list_of_path, &end, &start);
		ft_reinit_room(room);
	}
	if (list_of_path == NULL)
		ft_printf("Error path\n");
	else
		ft_print_pathlist(&list_of_path);
//	ft_send_ants(&list_of_path, anthill->nb_ant);
	return (1);
}

void	ft_reinit_room(t_room **room)
{
	t_room *elem;

	elem = *room;
	while (elem)
	{
		elem->explored = 0;
		elem->index = 0;
		elem->parent = NULL;
		elem = elem->next;
	}
}

int		ft_connection_use(t_room **room)
{
	int	i;

	i = 0;
	while (room[i])
	{
		if (room[i]->use == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_shortest_path(t_room **start)
{
	t_lst	*list_to_explore;
	t_room	*head;
	t_room	*parent;
	int		i;

	list_to_explore = NULL;
	add_list_to_explore(start, &list_to_explore);
	(*start)->explored = 1;
	while (list_to_explore)
	{
		head = list_to_explore->elem;
		parent = head;
		i = 0;
		while (head->connection[i])
		{
			//voir pour mieux gerer le cas de connection index = 0 et parent index = 0
			if (head->connection[i]->explored == 0 && head->connection[i]->index <= parent->index && head->connection[i]->use == 0)
			{
				head->connection[i]->parent = parent;
				head->connection[i]->index = parent->index + 1;
				head->connection[i]->explored = 1;
				add_list_to_explore(&head->connection[i], &list_to_explore);
			}
			i++;
		}
		del_list_to_explore(&list_to_explore);
	}
}

void	add_list_to_explore(t_room **elem, t_lst **list_to_explore)
{
	t_lst	*tmp;
	t_lst	*to_add;
	t_room	*room;

	room = NULL;
	to_add = NULL;
	tmp = *list_to_explore;
	if (!(to_add = (t_lst *)malloc(sizeof(t_lst))))
		ft_exit_malloc();
	to_add->elem = *elem;
	to_add->next = NULL;

	if (*list_to_explore == NULL)
		*list_to_explore = to_add;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
	}
}

void	del_list_to_explore(t_lst **list)
{
	t_lst *tmp;

	tmp = *list;
	*list = (*list)->next;
	ft_memdel((void**)&tmp);
}

/*  ALGO PARCOUR LARGEUR

// Reflechir au nombre de chemin a emprunter en fonction du nombre de foumies
// a faire traverser.



start->compteur = 0
fonction add_list(start, list)


function de calcul des chemins les plus courts

	while (list)

		Function list_head = get_element(list)
		parent = list_head;
		while (list_head->connection[i])
			If si connection[i]->explored == 0 || connection[i]->compteur > parent->compteur + 1.
				conneciton[i]->parent = parent;
				connection[i]->compteur = parent->compteur + 1;
				connection[i]->explored = 1;
				fonction add_list(connection[i], list)
			else
		fonction del_first_list(list);

while (chemin possible)

	function de calcul des chemins les plus courts
	function qui remonte chemin le plus court et supprime toutes les connections.
	et sauvagrde dans une liste

si chemin_possible = Error


*/
