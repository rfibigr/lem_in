/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:39:28 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/26 17:20:40 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_anthill	anthill;
	t_room		*list_room;
	char		*str;

	list_room = NULL;
	str	= NULL;
	init_anthill(&anthill);
	while (get_next_line(0, &str))
	{
		if(create_list(&anthill, &list_room, str) == 0)
			break;
		add_input(&anthill.input, str);
		ft_memdel((void**)&str);
	}
	ft_memdel((void**)&str);
	if (!(test_anthill(anthill, list_room)))
	{
		free_all(anthill.input, list_room);
		ft_printf("Error\n");
		return (0);
	}
	print_room(list_room, anthill);
	free_all(anthill.input, list_room);
	return (0);
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
		ft_printf("end : %s\n", anthill.end->name);
		ft_printf("NB ant : %d\n", anthill.nb_ant);
	ft_printf("============/INFO============\n");
}
