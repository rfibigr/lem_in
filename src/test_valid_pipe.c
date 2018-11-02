/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:18:16 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 19:44:59 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_pipe(char *str)
{
	int i;

	i = 0;
	if (!(ft_isascii(str[0])))
		return (0);
	while (str[i] != '-' && str[i])
	{
		if (!(ft_isascii(str[i])))
			return (0);
		i++;
	}
	if (str[i] == 0)
		return (0);
	i++;
	while (str[i])
	{
		if (!(ft_isascii(str[i])))
			return (0);
		i++;
	}
	if (!(ft_isascii(str[i - 1])))
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
	i = 0;
	while (split[0][i])
	{
		if (!(ft_isascii(split[0][i])))
			return (0);
		i++;
	}
	i = 0;
	while (split[1][i])
	{
		if (!(ft_isascii(split[1][i])))
			return (0);
		i++;
	}
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
