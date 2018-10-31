/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:51:33 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/31 17:27:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_create_room(t_anthill *anthill, t_room **room, char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
		i++;
	if (i != 3 || room_valid_format(split) == 0)
	{
		free_split(split);
		ft_printf("error : room format\n");
		return (0);
	}
	if (!(check_duplicate_room(room, split[0])))
	{
		free_split(split);
		ft_printf("error check duplicate room\n");
		return (0);
	}
	add_room_lst(room, split, anthill);
	free_split(split);
	return (1);
}

int		check_duplicate_room(t_room **room, char *name)
{
	t_room *tmp;

	tmp = *room;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->name, name)))
		{
			ft_printf("%s | %s\n", tmp->name, name);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	add_room_lst(t_room **room, char **split, t_anthill *anthill)
{
	t_room	*elem;

	elem = ft_create_elem_room(split);
	if (anthill->command == START)
		anthill->start = elem;
	else if (anthill->command == END)
		anthill->end = elem;
	anthill->command = 0;
	elem->next = *room;
	*room = elem;
}

t_room	*ft_create_elem_room(char **split)
{
	t_room	*elem;

	if (!(elem = (t_room*)malloc(sizeof(t_room))))
		ft_exit_malloc();
	elem->name = ft_strdup(split[0]);
	elem->x_coord = ft_atoi(split[1]);
	elem->y_coord = ft_atoi(split[2]);
	elem->explored = 0;
	elem->index = 0;
	elem->use = 0;
	elem->parent = NULL;
	elem->next = NULL;
	elem->connection = NULL;
	return (elem);
}
