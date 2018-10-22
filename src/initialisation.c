/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:30:26 by rfibigr           #+#    #+#             */
/*   Updated: 2018/10/22 18:32:15 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_anthill(t_anthill *anthill)
{
	anthill->nb_ant = 0;
	anthill->nb_start_pipe = 0;
	anthill->nb_end_pipe = 0;
	anthill->start = NULL;
	anthill->end = NULL;
}
