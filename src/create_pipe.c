/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:02:05 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 12:23:33 by rfibigr          ###   ########.fr       */
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
	if (!(add_pipe_lst(room, split)))
	{
		free_split(split);
		ft_printf("error room doesnt exist\n");
		return (0);
	}
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
			while (tmp->connection[i])
			{
				if (!(ft_strcmp(tmp->connection[i]->name, name_two)))
					return (0);
				i++;
			}
		}
		tmp = tmp->next;
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
