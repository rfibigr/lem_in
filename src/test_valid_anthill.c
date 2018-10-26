/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_anthill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:35:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/26 17:17:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		test_anthill(t_anthill anthill, t_room *room)
{
	if (room == NULL || anthill.start == NULL || anthill.end == NULL
		|| anthill.input == NULL)
	{
		ft_printf("room\n");
		return (0);
	}
	return (1);
}

int		pipe_valid_format(char **split)
{
	if (!(split[0] && split[1]))
		return (0);
	if (!(ft_isnumber(split[0])) && !(ft_isnumber(split[1])))
		return (0);
	return (1);
}

int		room_valid_format(char **split)
{
	if (!(split[0] && split[1] && split[2]))
		return (0);
	if (!(ft_isnumber(split[2])) && !(ft_isnumber(split[1])))
		return (0);
	return (1);
}
