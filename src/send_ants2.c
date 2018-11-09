/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:21:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 10:03:14 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_ant(t_ant **ant_list, t_list *path_list, int *ant_start)
{
	t_ant	*ant_list_free;

	if (!(ant_list_free = skip_used_ant(ant_list)))
		return ;
	ant_list_free->path = path_list->content;
	ant_list_free = ant_list_free->next;
	(*ant_start)--;
	path_list = path_list->next;
	while (path_list && ant_list_free)
	{
		if (*ant_start > (int)path_list->content_size)
		{
			ant_list_free->path = path_list->content;
			ant_list_free = ant_list_free->next;
			(*ant_start)--;
		}
		path_list = path_list->next;
	}
}

t_ant	*skip_used_ant(t_ant **ant_list)
{
	t_ant	*ant_list_free;

	ant_list_free = *ant_list;
	while (ant_list_free->path && ant_list_free)
	{
		ant_list_free = ant_list_free->next;
	}
	return (ant_list_free);
}

void	move_ant(t_ant **ant_list)
{
	t_ant	*ant;
	t_list	*path;

	ant = *ant_list;
	path = NULL;
	while (ant)
	{
		if (!(ant->path))
			break ;
		path = ant->path;
		path = path->next;
		ant->path = path;
		ant = ant->next;
	}
}

void	delete_ant_arrived(t_ant **ant_list, char *end_name)
{
	t_ant	*ant;
	t_room	*room;

	ant = *ant_list;
	if (ant == NULL || ant->path == NULL)
		return ;
	room = ant->path->content;
	while (ant)
	{
		if (!(ant->path))
			break ;
		room = ant->path->content;
		if (!ft_strcmp(room->name, end_name))
			ft_delete_ant(&ant, ant_list);
		else
			ant = ant->next;
	}
}

void	ft_delete_ant(t_ant **ant, t_ant **ant_list)
{
	t_ant	*previous;

	previous = (*ant)->previous;
	if (previous == NULL)
	{
		(*ant_list) = (*ant_list)->next;
		if (*ant_list)
			(*ant_list)->previous = NULL;
	}
	else
	{
		(*ant)->next->previous = (*ant)->previous;
		(*ant)->previous->next = (*ant)->next;
	}
	ft_memdel((void**)ant);
	*ant = *ant_list;
}
