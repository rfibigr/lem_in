/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:31:30 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 16:24:12 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit_error(t_list *input, t_room *room)
{
	free_all(input, room);
	exit(1);
}

void	ft_exit_malloc(void)
{
	ft_printf("malloc fail");
	exit(1);
}

void	free_all(t_list *input, t_room *room)
{
	t_room	*tmp;
	t_list	*lst_tmp;

	while (input)
	{
		lst_tmp = input;
		input = (input)->next;
		ft_memdel((void**)&(lst_tmp->content));
		ft_memdel((void**)&lst_tmp);
	}
	while (room)
	{
		tmp = room;
		room = room->next;
		if (tmp->connection)
			ft_memdel((void**)&(tmp->connection));
		ft_memdel((void**)&(tmp->name));
		ft_memdel((void**)&tmp);
	}
}

void	free_loop(t_list *input, t_room *room, t_list *path_list)
{
	t_list *path_list_tmp;
	t_list *path;
	t_list *path_tmp;

	path_list_tmp = path_list;
	while (path_list)
	{
		path = path_list->content;
		while (path)
		{
			path_tmp = path;
			path = path->next;
			ft_memdel((void**)&path_tmp);
		}
		path_list_tmp = path_list;
		path_list = path_list->next;
		ft_memdel((void**)&path_list_tmp);
	}
	free_all(input, room);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_memdel((void**)&(split[i]));
		i++;
	}
	ft_memdel((void**)&split);
}
