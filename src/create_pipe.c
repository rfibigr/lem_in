/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:02:05 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/26 17:08:48 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_create_pipe(t_anthill *anthill, t_room **room, char *str)
{
	char	**split;
	int		i;

	anthill->command = 0;
	anthill->input_pipe = 1;
	i = 0;
	split = ft_strsplit(str, '-');
	while (split[i])
		i++;
	if (i != 2 || pipe_valid_format(split) == 0)
	{
		free_split(split);
		ft_printf("error : pipe format\n");
		return (0);
	}
	if (!(check_duplicate_pipe(room, split[0], split[1])))
	{
		free_split(split);
		ft_printf("error check duplicate pipe\n");
		return (0);
	}
	add_pipe_lst(room, split);
	return (1);
}

int		check_duplicate_pipe(t_room **room, char *name_one, char *name_two)
{
	t_room	*tmp;
	int		i;

	tmp = *room;
	i = 0;
	if (!(ft_strcmp(name_one, name_two)))
		return (0);
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name, name_one)))
		{
			if (tmp->connection)
			{
				while (tmp->connection[i])
				{
					if (!(ft_strcmp(tmp->connection[i]->name, name_two)))
						return (0);
					i++;
				}
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

void	add_pipe_lst(t_room **room, char **split)
{
	t_room	*elem_one;
	t_room	*elem_two;

	elem_one = ft_search_name(room, split[0]);
	elem_two = ft_search_name(room, split[1]);
	ft_create_elem_pipe(&elem_one, elem_two);
	ft_create_elem_pipe(&elem_two, elem_one);
	free_split(split);
}

void	ft_create_elem_pipe(t_room **elem_room, t_room *elem_connected)
{
	t_room	**tab_connection;

	tab_connection = NULL;
	if ((*elem_room)->connection == NULL)
	{
		if (!(tab_connection = (t_room**)malloc(sizeof(t_room *) * 2)))
			ft_exit_malloc();
		tab_connection[0] = elem_connected;
		tab_connection[1] = NULL;
		(*elem_room)->connection = tab_connection;
	}
	else
		add_elem_connection(elem_room, elem_connected);
}

void	add_elem_connection(t_room **elem_room, t_room *elem_connected)
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
	len = len + 1;
	tab_new[len] = NULL;
	ft_memdel((void **)&((*elem_room)->connection));
	(*elem_room)->connection = tab_new;
}
