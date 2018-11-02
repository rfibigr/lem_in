/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:03:31 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 14:38:36 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_reinit_room(t_room **room, int option_use)
{
	t_room *elem;

	elem = *room;
	while (elem)
	{
		elem->explored = 0;
		elem->index = 0;
		elem->parent = NULL;
		if (option_use == 1)
			elem->use = 0;
		elem = elem->next;
	}
}

int		ft_connection_use(t_room **room)
{
	int	i;

	i = 0;
	while (room[i])
	{
		if (room[i]->use == 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_condition_to_explore(t_room *room, int index)
{
	if (room->explored == 0 && room->index <= index && room->use == 0)
		return (1);
	return (0);
}

int		ft_tablen(t_room **tab)
{
	int	i;

	i = 0;
	while(tab[i])
		i++;
	return(i);
}
