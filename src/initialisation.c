/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:30:26 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/02 19:41:46 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_anthill(t_anthill *anthill)
{
	anthill->nb_ant = 0;
	anthill->command = 0;
	anthill->input_pipe = 0;
	anthill->start = NULL;
	anthill->end = NULL;
}

void	init_room(t_room **elem)
{
	(*elem)->name = NULL;
	(*elem)->x_coord = 0;
	(*elem)->y_coord = 0;
	(*elem)->explored = 0;
	(*elem)->index = 0;
	(*elem)->use = 0;
	(*elem)->parent = NULL;
	(*elem)->next = NULL;
	if (!((*elem)->connection = (t_room**)malloc(sizeof(t_room *) * 2)))
			ft_exit_malloc();;
	(*elem)->connection[0] = NULL;
}
