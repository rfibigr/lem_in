/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:51:33 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 16:51:34 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_create_room(t_anthill *anthill, t_room **room, char *str)
{
	char	**split;

	split = ft_strsplit(str, ' ');
	if (room_valid_format(room, split))
		add_room_lst(room, split, anthill);
	else
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

void	add_room_lst(t_room **room, char **split, t_anthill *anthill)
{
	t_room	*elem;

	if (!(elem = (t_room*)malloc(sizeof(t_room))))
		ft_exit_malloc();
	init_room(&elem);
	elem->name = ft_strdup(split[0]);
	elem->x_coord = ft_atoi(split[1]);
	elem->y_coord = ft_atoi(split[2]);
	if (anthill->command == START)
	{
		elem->color = 0x008000;
		anthill->start = elem;
	}
	else if (anthill->command == END)
	{
		elem->color = 0XFF0000;
		anthill->end = elem;
	}
	anthill->command = 0;
	elem->next = *room;
	*room = elem;
}
