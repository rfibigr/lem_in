/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:02:05 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/06 15:46:14 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_create_pipe(t_anthill *anthill, t_room **room, char *str)
{
	char	**split;

	if (!*room)
		return (0);
	anthill->command = 0;
	anthill->input_pipe = 1;
	split = ft_strsplit(str, '-');
	if (pipe_valid_format(room, split))
	{
		if (!(add_pipe_lst(room, split)))
			return (0);
	}
	else
	{
		free_split(split);
		return (0);
	}
	return (1);
}

int		add_pipe_lst(t_room **room, char **split)
{
	t_room	*elem_one;
	t_room	*elem_two;

	elem_one = ft_search_name(room, split[0]);
	elem_two = ft_search_name(room, split[1]);
	if (elem_one == NULL || elem_two == NULL)
		return (0);
	ft_create_elem_pipe(&elem_one, elem_two);
	ft_create_elem_pipe(&elem_two, elem_one);
	free_split(split);
	return (1);
}

void	ft_create_elem_pipe(t_room **elem_room, t_room *elem_connected)
{
	t_room	**tab_connection;
	t_room	**tab_new;
	int		len;

	tab_new = NULL;
	len = 0;
	tab_connection = (*elem_room)->connection;
	while (tab_connection[len])
		len++;
	if (!(tab_new = (t_room**)malloc(sizeof(t_room *) * (len + 2))))
		ft_exit_malloc();
	len = 0;
	while (tab_connection[len])
	{
		tab_new[len] = tab_connection[len];
		len++;
	}
	tab_new[len] = elem_connected;
	tab_new[len + 1] = NULL;
	ft_memdel((void **)&((*elem_room)->connection));
	(*elem_room)->connection = tab_new;
}

t_room	*ft_search_name(t_room **room, char *name)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name, name)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
