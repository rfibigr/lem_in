/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:21:29 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 17:56:42 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_send_ant(t_list **path_list, int nb_ant, char *end_name)
{
	// ecrire dans anthill
	int		ant_start;
	t_ant	*ant_list;

	ant_list = NULL;
	ant_start = nb_ant;
	create_ant_list(&ant_list, nb_ant);
	ft_add_size_to_path(path_list);
	while (ant_list)
	{
		move_ant(&ant_list);
		if (ant_start > 0)
			start_ant(&ant_list, *path_list, &ant_start);
		print_ant_list(ant_list);
		delete_ant_arrived(&ant_list, end_name);
	}
}


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

t_ant 	*skip_used_ant(t_ant **ant_list)
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
	t_ant	*previous;

	ant = *ant_list;
	room = ant->path->content;
	while (ant)
	{
		if(!(ant->path))
			break ;
		room = ant->path->content;
		if(!ft_strcmp(room->name, end_name))
		{
			previous = ant->previous;
			if (previous == NULL)
			{
				*ant_list = (*ant_list)->next;
				if (*ant_list)
					(*ant_list)->previous = NULL;
			}
			else
			{
				ant->next->previous = ant->previous;
				ant->previous->next = ant->next;
			}
			ft_memdel((void**)&ant);
			ant = *ant_list;
		}
		else
			ant = ant->next;
	}
}

void	create_ant_list(t_ant **ant_list, int nb_ant)
{
	t_ant *ant;

	while (nb_ant)
	{
		if(!(ant = (t_ant*)malloc(sizeof(t_ant))))
			ft_exit_malloc();
		ant->name = nb_ant;
		ant->path = NULL;
		ant->next = NULL;
		ant->previous = NULL;

		if (*ant_list == NULL)
			*ant_list = ant;
		else
		{
			ant->next = *ant_list;
			(*ant_list)->previous = ant;
			*ant_list = ant;
		}
		nb_ant--;
	}
}

void	ft_add_size_to_path(t_list **list_of_path)
{
	t_list	*path;
	t_list *tmp;

	tmp = *list_of_path;
	path = NULL;
	while (tmp)
	{
		path = tmp->content;
		tmp->content_size = ft_list_size(path) - 1;
		tmp = tmp->next;
	}
}
