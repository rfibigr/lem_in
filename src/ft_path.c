/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:03:31 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/01 16:10:56 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		if (!(ft_add_path(&list_of_path, &end, &start)))
			break ;
		ft_reinit_room(room);
	}
	if (list_of_path == NULL)
		ft_printf("Error path\n");
	else
	{
		ft_print_pathlist(&list_of_path);
		ft_send_ant(&list_of_path, anthill->nb_ant, end->name);
	}
	//free path;
	return (1);
}

void	ft_shortest_path(t_room **start)
{
	t_lst	*list_to_explore;
	t_room	*head;
	t_room	*parent;
	int		i;

	list_to_explore = NULL;
	add_list_to_explore(start, &list_to_explore);
	while (list_to_explore)
	{
		head = list_to_explore->elem;
		parent = head;
		i = 0;
		while (head->connection[i])
		{
			if (ft_condition_to_explore(head->connection[i], parent->index))
			{
				head->connection[i]->parent = parent;
				head->connection[i]->index = parent->index + 1;
				add_list_to_explore(&head->connection[i], &list_to_explore);
			}
			i++;
		}
		del_list_to_explore(&list_to_explore);
	}
}

int		ft_add_path(t_list **path_list, t_room **end, t_room **start)
{
	t_list	*path;
	t_room	*room;

	path = NULL;
	room = (*end)->parent;
	if (!room)
		return (0);
	//OPTIONNELLE
	ft_list_push_front(&path, *end);
	while (room->name != (*start)->name)
	{
		room->use = 1;
		ft_list_push_front(&path, room);
		room = room->parent;
	}
	//OPTIONNELLE
	//ft_list_push_front(&path, room);
	ft_list_push_back(path_list, path);
	return (1);
}

void	add_list_to_explore(t_room **elem, t_lst **list_to_explore)
{
	t_lst	*tmp;
	t_lst	*to_add;

	(*elem)->explored = 1;
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
