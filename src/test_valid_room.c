/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:26:46 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/06 13:39:17 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_room(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (i < 5)
		return (0);
	if (str[0] == ' ' || str[i-1] == ' ' || count != 2)
		return (0);
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
	if (!(ft_isinteger(split[2])) || !(ft_isinteger(split[1])))
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
