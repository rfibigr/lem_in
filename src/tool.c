/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:42:19 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/01 22:56:00 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_tablen(t_room **tab)
{
	int	i;

	i = 0;
	while(tab[i])
		i++;
	return(i);
}

void	print_room(t_room *room, t_anthill anthill)
{
	t_room **connection;
	int i;
	t_list *list;


	ft_printf("=============INPUT===========\n");
		list = anthill.input;
		while (list)
		{
			ft_printf("%s", list->content);
			ft_printf("\n");
			list = list->next;
		}
	ft_printf("============/INPUT===========\n\n");

	ft_printf("=============ROOM============\n");
		while (room)
		{
			connection = room->connection;
			ft_printf("-----------------------\n");
			ft_printf("NAME : %s\n", room->name);
			ft_printf("X : %d\n", room->x_coord);
			ft_printf("Y : %d\n", room->y_coord);
			if (room->parent)
				ft_printf("Parent : %s\n", room->parent->name);
			ft_printf("USE : %d\n", room->use);
			ft_printf("Explored : %d\n", room->explored);
			ft_printf("Index : %d\n", room->index);
			ft_printf("---LINK---\n");
			i = 0;
			if (connection)
			{
				while (connection[i])
				{
					ft_printf("|%s|\n", connection[i]->name);
					i++;
				}
			}
			ft_printf("--/LINK---\n");
			ft_printf("-----------------------\n\n");
			room = room->next;
		}
	ft_printf("============/ROOM============\n");

	ft_printf("\n=============INFO============\n");
		ft_printf("start : %s\n", anthill.start->name);
		ft_printf("start nb_connection : %d\n", anthill.nb_start_pipe);
		ft_printf("end : %s\n", anthill.end->name);
		ft_printf("end nb_connection : %d\n", anthill.nb_end_pipe);
		ft_printf("NB ant : %d\n", anthill.nb_ant);
	ft_printf("============/INFO============\n");
}


void	print_explore(t_list *list)
{
	int i;
	t_room *room;

	i = 0;
	while (list)
	{
		room = list->content;
		ft_printf("list[%d]=", i);
		ft_printf("name|%s|\n", room->name);
		ft_printf("x|%d|\n", room->x_coord);
		ft_printf("y|%d|\n", room->y_coord);
		list = list->next;
		i++;
	}
}

void	ft_print_pathlist(t_list **list_of_path)
{
	int	i;
	t_list	*tmp;
	t_list	*path;
	t_room	*room;

	tmp = (*list_of_path);
	room = NULL;
	i = 0;
	while (tmp)
	{
		ft_printf("----------PATH NUMBER %d-------------\n", i);

		path = tmp->content;
		while (path)
		{
			room = path->content;
			ft_printf("Room name : %s\n", room->name);
			path = path->next;
		}
		ft_printf("------- END PATH NUMBER %d ----------\n", i );
		i++;
		tmp = tmp->next;
	}

}

void	print_room_solo(t_room *room)
{
	t_room **connection;
	int i;

	ft_printf("=============ROOM============\n");
			connection = room->connection;
			ft_printf("-----------------------\n");
			ft_printf("NAME : %s\n", room->name);
			ft_printf("X : %d\n", room->x_coord);
			ft_printf("Y : %d\n", room->y_coord);
			if (room->parent)
				ft_printf("Parent : %s\n", room->parent->name);
			ft_printf("USE : %d\n", room->use);
			ft_printf("Explored : %d\n", room->explored);
			ft_printf("Index : %d\n", room->index);
			ft_printf("---LINK---\n");
			i = 0;
			if (connection)
			{
				while (connection[i])
				{
					ft_printf("|%s|\n", connection[i]->name);
					i++;
				}
			}
			ft_printf("--/LINK---\n");
			ft_printf("-----------------------\n\n");
	ft_printf("============/ROOM============\n");
}

void	print_ant(t_ant *ant)
{
	t_room	*room;
	t_list	*path;

	room = NULL;
	ft_printf("=============ANT============\n");
	while(ant)
	{
		path = ant->path;
		if (path)
			room = path->content;
		ft_printf("-----------------------\n");
		ft_printf("NAME : %d\n", ant->name);
		if (path)
			ft_printf("PATH : %s\n", room->name);
		else
			ft_printf("PATH : %s\n", path);
		ft_printf("-----------------------\n\n");
		ant = ant->next;
	}
	ft_printf("============/ANT============\n");
}
