/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:03:31 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/29 17:57:39 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	on entre les valeurs dans anthill START
	on parcourt le graphe en largeur
*/


int		ft_path(t_anthill *anthill)
{
	t_room	*start;
	t_room	*end;
	t_list	*list_of_path;

	list_of_path = NULL;
	start = anthill->start;
	end = anthill->end;
	anthill->nb_start_pipe = ft_tablen(start->connection);
	anthill->nb_end_pipe = ft_tablen(end->connection);

//TEST TO DELETE
//	ft_shortest_path(&start);
//ENDTEST
	while (end->connection)
	{
		ft_shortest_path(&start);
		ft_add_path(&list_of_path, &end, &start);
	}
	if (list_of_path == NULL)
		ft_printf("Error path\n");
	//ft_send_ants(&list_of_path, anthill->nb_ant);
	return (1);
}

void	ft_shortest_path(t_room **start)
{
	t_list	*list_to_explore;
	t_room	*head;
	t_room	*parent;
	int		i;

	list_to_explore = NULL;
	add_list_to_explore(start, &list_to_explore);
	(*start)->explored = 1;
	while (list_to_explore)
	{
		ft_printf("while -------------- LSTEXPLORE ------------ \n");
		print_explore(list_to_explore);
		ft_printf("------- ENDLIST EXPLORE ------------- \n");
		head = list_to_explore->content;
		parent = head;
		i = 0;
		while (head->connection[i])
		{
			ft_printf("while -----------CONNECTION----------\n");

			ft_printf("name = %s, head->connection[i]->explored = |%d|, head->connection[i]index = |%d|, parent->index = |%d|\n",
			head->connection[i]->name, head->connection[i]->explored, head->connection[i]->index, parent->index);
			ft_printf("-----------ENDCONNECTION----------\n");
			//voir pour mieux gerer le cas de connection index = 0 et parent index = 0
			if (head->connection[i]->explored == 0 && head->connection[i]->index <= parent->index)
			{
				ft_printf("IF add to explore\n");
				head->connection[i]->parent = parent;
				head->connection[i]->index = parent->index + 1;
				head->connection[i]->explored = 1;
				add_list_to_explore(&head->connection[i], &list_to_explore);
			}
			i++;
		}
		print_explore(list_to_explore);
		del_list_to_explore(&list_to_explore);
		ft_printf("DEL -------------- LSTEXPLORE ------------ \n");
		print_explore(list_to_explore);
		ft_printf("------- ENDLIST EXPLORE ------------- \n");
	}
}

void	add_list_to_explore(t_room **elem, t_list **list_to_explore)
{
	if (*list_to_explore == NULL)
	{
		ft_printf("add to explore first elem\n");
		*list_to_explore = ft_lstnew(*elem, sizeof(**elem));
	}
	else
	{
		ft_printf("Push back to explore elem\n");
		ft_list_push_back(list_to_explore, *elem, sizeof(**elem));
	}
}

void	del_list_to_explore(t_list **list)
{
	t_list *tmp;

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
