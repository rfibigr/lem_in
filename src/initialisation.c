/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:30:26 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/08 18:43:44 by rfibigr          ###   ########.fr       */
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
	(*elem)->color = 0xFFFFFF;
	(*elem)->explored = 0;
	(*elem)->index = 0;
	(*elem)->use = 0;
	(*elem)->parent = NULL;
	(*elem)->next = NULL;
	if (!((*elem)->connection = (t_room**)malloc(sizeof(t_room *) * 2)))
			ft_exit_malloc();;
	(*elem)->connection[0] = NULL;
}

t_mlx	init_windows(void)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.name = mlx_new_window(mlx.init, IMG_X, IMG_Y, "Lem-In");
	mlx.image = mlx_new_image(mlx.init, IMG_X, IMG_Y);
	mlx.str = mlx_get_data_addr(mlx.image, &mlx.bpp,
												&mlx.size_line, &mlx.endian);
	return (mlx);
}

t_loop	init_loop(void)
{
	t_loop	loop;

	loop.path = NULL;
	loop.room = NULL;
	loop.ant_list = NULL;
	loop.speed = 0;
	loop.start = 0;
	return (loop);
}
