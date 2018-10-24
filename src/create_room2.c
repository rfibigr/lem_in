/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:18:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/24 10:43:01 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room_lst(t_room **room, char **split, t_anthill *anthill)
{
	t_room *elem;

	elem = ft_create_elem_room(split);
	if (anthill->command == START)
		anthill->start = elem;
	else if (anthill->command == END)
		anthill->end = elem;
	elem->next = *room;
	*room = elem;
}

t_room	*ft_create_elem_room(char **split)
{
	t_room *elem;

	elem = (t_room*)malloc(sizeof(t_room));
	elem->name = split[0];
	elem->x_coord = ft_atoi(split[1]);
	elem->y_coord = ft_atoi(split[2]);
	elem->already_pass = 0;
	elem->next = NULL;
	elem->connection = NULL;
	free(split[1]);
	free(split[2]);
	return(elem);
}

void	add_pipe_lst(t_room **room, char **split, t_anthill *anthill)
{
	//search room with name
	//create link 

}
