/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:17:33 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/29 17:55:50 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_path(t_list **path_list, t_room **end, t_room **start)
{
	t_list *path;
	t_room	*room;

	path = NULL;
	room = *end;
	if (!(*end)->parent)
	{
		add_to_path(path_list, NULL);
		return;
	}
	add_to_path(path, room);
	room = room->parent;
	while (room != *start)
	{
		add_to_path(path, room);
		//delete connection;
		room = room->parent;
	}
	add_to_path(path_list, path);
}

void	add_to_path(t_list **path, t_list **elem)
{

}
