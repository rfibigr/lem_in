/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:17:33 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/29 21:56:36 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_path(t_list **path_list, t_room **end, t_room **start)
{
	t_list *path;
	t_room	*room;

	path = NULL;
	room = (*end)->parent;
	if (!room)
	{
		add_to_pathlist(path_list, NULL);
		return;
	}
	add_to_path(&path, end);
	while (room->name != (*start)->name)
	{
		room->use = 1;
		add_to_path(&path, &room);
		room = room->parent;
	}
	//OPTIONNELLE
	add_to_path(&path, &room);
	add_to_pathlist(path_list, &path);
}

//CREATE JUST ONE FUNCTION

void	add_to_path(t_list **path, t_room **elem)
{
	t_list	*to_add;

	to_add = (t_list *)malloc(sizeof(t_list));
	to_add->content = *elem;
	to_add->next = NULL;
	if (*path == NULL)
		*path = to_add;
	else
	{
		to_add->next = *path;
		*path = to_add;
	}
}

void	add_to_pathlist(t_list **path_list, t_list **elem)
{
	t_list	*to_add;

	to_add = (t_list *)malloc(sizeof(t_list));
	to_add->content = *elem;
	to_add->next = NULL;
	if (*path_list == NULL)
		*path_list = to_add;
	else
	{
		to_add->next = *path_list;
		*path_list = to_add;
	}
}
