/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:50:48 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/06 15:50:46 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ant_list(t_ant *ant_list)
{
	t_room *room;

	while (ant_list->path && ant_list)
	{
		room = ant_list->path->content;
		ft_printf("L%d-%s", ant_list->name, room->name);
		ant_list = ant_list->next;
		if (ant_list)
			write(1, " ", 1);
		else
			break ;
	}
	write(1, "\n", 1);
}

void		ft_send_all_ant(int nb_ant, char *end_name)
{
	int	i;

	i = 1;
	while (i <= nb_ant)
	{
		ft_printf("L%d-%s", i, end_name);
		if (i != nb_ant)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_input(t_list *list)
{
	while (list)
	{
		ft_printf("%s", list->content);
		ft_printf("\n");
		list = list->next;
	}
	ft_printf("\n");
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
		ft_printf("=========== PATH NUMBER %d =============\n", i);
		path = tmp->content;
		while (path)
		{
			room = path->content;
			ft_printf("Room name : %s\n", room->name);
			path = path->next;
		}
		ft_printf("========== /PATH NUMBER %d =============\n", i);
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
