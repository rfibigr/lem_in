/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_anthill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:35:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/25 20:48:05 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		test_anthill(t_anthill anthill, t_room *room)
{
	if (room == NULL )
	{
		ft_printf("room\n");
		return (0);
	}
	if (anthill.start == NULL)
	{
		ft_printf("start\n");
		return (0);
	}
	if (anthill.end == NULL)
	{
		ft_printf("end\n");
		return (0);
	}
	if (anthill.input == NULL)
	{
		ft_printf("input\n");
		return (0);
	}
	return (1);
}
