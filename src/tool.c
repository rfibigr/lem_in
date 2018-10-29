/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:42:19 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/29 16:47:30 by rfibigr          ###   ########.fr       */
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
