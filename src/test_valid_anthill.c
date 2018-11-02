/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_anthill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:35:24 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 19:45:06 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		test_anthill(t_anthill anthill, t_room *room)
{
	if (room == NULL)
	{
		ft_printf("No room\n");
		return (0);
	}
	if (anthill.start == NULL)
	{
		ft_printf("No command start\n");
		return (0);
	}
	if (anthill.end == NULL)
	{
		ft_printf("No command end\n");
		return (0);
	}
	if(test_valid_path(&anthill, &room) == 0)
	{
		ft_printf("No valid path\n");
		return (0);
	}
	return (1);
}

int		test_valid_path(t_anthill *anthill, t_room **room)
{
	t_room	*start;
	t_room	*end;

	start = anthill->start;
	end = anthill->end;
	if (start->connection == NULL || end->connection == NULL)
		return (0);
	ft_shortest_path(&start);
	if (end->parent == NULL)
		return (0);
	ft_reinit_room(room, 1);
	(void)room;
	return (1);
}
