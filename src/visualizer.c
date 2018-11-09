/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:57:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 14:05:59 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	visualizer(char **str, t_room *room, t_list *path_l, t_anthill anthill)
{
	t_mlx	mlx;
	t_loop	loop;
	t_scale	scale;

	str = str + 1;
	loop = init_loop();
	loop.path = path_l;
	loop.room = room;
	loop.anthill = anthill;
	create_ant_list(&loop.ant_list, anthill.nb_ant);
	loop.ant_start = anthill.nb_ant;
	mlx = init_windows();
	loop.mlx = mlx;
	scale = ft_calcul_size(room);
	ft_resize_coord(scale, room);
	trace_room(room, mlx);
	mlx_key_hook(mlx.name, key_hook, &loop);
	mlx_loop(mlx.init);
}

int		visualizer_ant(t_loop *loop)
{
	if (loop->ant_list == NULL)
		return (0);
	move_ant(&loop->ant_list);
	if (loop->ant_start > 0)
		start_ant(&loop->ant_list, loop->path, &loop->ant_start);
	print_pixel_ant(loop);
	delete_ant_arrived(&loop->ant_list, loop->anthill.end->name);
	usleep(3000000);
	return (0);
}

void	print_pixel_ant(t_loop *loop)
{
	char	*str;
	t_ant	*ant_list;
	t_room	*room;

	ant_list = loop->ant_list;
	room = loop->room;
	mlx_clear_window(loop->mlx.init, loop->mlx.name);
	trace_room(loop->room, loop->mlx);
	trace_path(loop->path, loop->mlx, loop->anthill.start);
	while (ant_list->path && ant_list)
	{
		room = ant_list->path->content;
		if (strcmp(room->name, loop->anthill.end->name))
		{
			str = ft_itoa(ant_list->name);
			mlx_string_put(loop->mlx.init, loop->mlx.name,
				room->x_coord, room->y_coord, 0, str);
			free(str);
		}
		ant_list = ant_list->next;
		if (ant_list == NULL)
			break ;
	}
}

int		key_hook(int key, t_loop *loop)
{
	if (key == 49 && loop->start == 1)
	{
		ft_printf("Pause\n", key);
		mlx_loop_hook(loop->mlx.init, stop_prog, loop);
		loop->start = 0;
		key = 0;
	}
	if (key == 49 && loop->start == 0)
	{
		ft_printf("Start\n", key);
		loop->start = 1;
		mlx_loop_hook(loop->mlx.init, visualizer_ant, loop);
	}
	if (key == 53)
	{
		free_loop(loop->input, loop->room, loop->path);
		exit(0);
	}
	return (0);
}

int		stop_prog(t_loop *loop)
{
	(void)loop;
	return (1);
}
