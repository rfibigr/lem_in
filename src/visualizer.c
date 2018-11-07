/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:57:32 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/07 20:59:08 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	visualizer(char **str, t_room *room, t_list *path, t_anthill anthill)
{
	t_mlx	mlx;

	//calcul longueur de str, si arg
	str = str + 1;
	if (!(ft_strcmp(*str, "-visualizer")))
	mlx = init_windows();
	draw_anthill(room, anthill, path, &mlx);
	mlx_key_hook(mlx.name, key_hook, room);
	mlx_loop(mlx.init);
}

void	draw_anthill(t_room *room, t_anthill anthill, t_list *path, t_mlx *mlx)
{
	(void)anthill;
	(void)path;

	t_scale	scale;
	scale = ft_calcul_size(room);
	ft_resize_coord(scale, room);
	print_room(room, anthill);
	trace_room(room, *mlx);
}

void	trace_square(int x1, int y1, int x2, int y2, t_mlx mlx)
{
	t_coord	up_left;
	t_coord	up_right;
	t_coord	down_right;
	t_coord	down_left;

	up_left.x = x1;
	up_left.y = y1;
	up_right.x = x2;
	up_right.y = y1;
	down_left.x = x1;
	down_left.y = y2;
	down_right.x = x2;
	down_right.y = y2;
	ft_bresenham(up_left, up_right, mlx, 0xFFFFFF);
	ft_bresenham(up_left, down_left, mlx, 0xFFFFFF);
	ft_bresenham(up_right, down_right, mlx, 0xFFFFFF);
	ft_bresenham(down_left, down_right, mlx, 0xFFFFFF);
}

void	trace_room(t_room *room, t_mlx mlx)
{
	t_coord	start;
	t_coord	end;
	int	i;

	while(room)
	{
		//trace room
		trace_square(room->x_coord - 25, room->y_coord + 25,
			room->x_coord + 25, room->y_coord - 25, mlx);
		//trace connection
		i = 0;
		while (room->connection[i])
		{
			ft_printf("room name = %s\n", room->name);
			start.x = room->x_coord;
			start.y = room->y_coord;
			end.x = room->connection[i]->x_coord;
			end.y = room->connection[i]->y_coord;
			ft_printf("x1 = %d | y1 = %d | x2 = %d | y2 = %d \n", start.x, start.y, end.x, end.y);
			ft_bresenham(start, end, mlx, 0xFFFFFF);
			i++;
		}
		room = room ->next;
	}
}




int		key_hook(int key, t_room *room)
{
	(void)room;
	ft_printf("key = %d\n", key);
	if (key == 65307)
	{
		//free all
		exit(0);
	}
	return (0);
}
//
// void	fill_line(char **img_str, int x, int y, int len)
// {
// 	int	i;
// 	int color;
//
// 	i = x;
// 	color = color_element(len);
// 	if (len > 0)
// 	{
// 		while (len > 0)
// 		{
// 			fill_pixel(img_str, i, y, color);
// 			i++;
// 			len--;
// 		}
// 	}
// 	else
// 	{
// 		while (len < 0)
// 		{
// 			fill_pixel(img_str, i, y, color);
// 			i--;
// 			len++;
// 		}
// 	}
// }
//
// int		color_element(int len)
// {
// 	int color;
//
// 	if (len < 0)
// 		color = 0xfff000;
// 	else
// 		color = 0x000fff;
// 	return (color);
// }
