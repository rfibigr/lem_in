/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:18:16 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/08 11:14:24 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_pipe(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	if (i < 3)
		return (0);
	if (str[0] == '-' || str[i-1] == '-' || count != 1)
		return (0);
	return (1);
}

int		pipe_valid_format(t_room **room, char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	if (i != 2)
		return (0);
	if (!(split[0] && split[1]))
		return (0);
	if (!(check_duplicate_pipe(room, split[0], split[1])))
		return (0);
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
