/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:26:46 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 19:25:39 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_room(char *str)
{
	int i;

	i = 0;
	if (!(ft_isascii(str[0])))
		return (0);
	while (str[i] != ' ' && str[i])
	{
		if (!(ft_isascii(str[i])))
			return (0);
		i++;
	}
	if (str[i] == 0)
		return (0);
	i++;
	while (str[i] != ' ' && str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (str[i] == 0)
		return (0);
	i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int		room_valid_format(t_room **room, char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (0);
	if (!(split[0] && split[1] && split[2]))
		return (0);
	if (!(ft_isnumber(split[2])) && !(ft_isnumber(split[1])))
		return (0);
	if (!(check_duplicate_room(room, split[0])))
		return (0);
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
