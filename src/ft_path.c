/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:03:31 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/27 21:08:47 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	on entre les valeurs dans anthill START
	on entre


*/


int		ft_path(t_anthill *anthill, t_room *room)
{
	(void)room;
	anthill->nb_start_pipe = ft_tablen(anthill->start->connection);
	anthill->nb_end_pipe = ft_tablen(anthill->end->connection);


	return (0);
}
