/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_scale.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:58:08 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/07 19:12:28 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_scale		ft_calcul_size(t_room *room)
{
	t_scale	scale;

	scale.x_min = room->x_coord;
	scale.x_max = room->x_coord;
	scale.y_min = room->y_coord;
	scale.y_max = room->y_coord;
	while (room)
	{
		if (room->x_coord < scale.x_min)
			scale.x_min = room->x_coord;
		if (room->x_coord > scale.x_max)
			scale.x_max = room->x_coord;
		if (room->y_coord < scale.y_min)
			scale.y_min = room->y_coord;
		if (room->y_coord > scale.y_max)
			scale.y_max = room->y_coord;
		room = room->next;
	}
	return (scale);
}

void		ft_resize_coord(t_scale scale, t_room *room)
{
	int		ratio_x;
	int		ratio_y;

	ratio_x = (IMG_X - 100) / (scale.x_max - scale.x_min);
	ratio_y = (IMG_Y - 100) / (scale.y_max - scale.y_min);
	if (ratio_x < ratio_y)
		scale.ratio = ratio_x;
	else
		scale.ratio = ratio_y;
	scale.decal_x = -1 * (scale.x_min * scale.ratio) + 50;
	scale.decal_y = (scale.y_max * scale.ratio) + 50;

	// ft_printf("xmin = %d | xmax = %d | ymin = %d | ymax = %d |\n",
	// 		scale.x_min, scale. x_max, scale.y_min, scale.y_max);
	// ft_printf("ratio_x = %d | ratio_y = %d | ratio = %d\n",ratio_x, ratio_y, scale.ratio);
	// ft_printf("decalx = %d | decaly %d\n", scale.decal_x, scale.decal_y);

	while (room)
	{
		room->x_coord = room->x_coord * (scale.ratio) + scale.decal_x;
		room->y_coord =  - room->y_coord * (scale.ratio) + scale.decal_y;
		room = room->next;
	}
}
