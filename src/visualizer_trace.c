/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:22:10 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/09 10:56:35 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	trace_square(t_coord middle, int wide, int color, t_mlx mlx)
{
	t_coord	up_left;
	t_coord	up_right;

	up_left.x = middle.x - wide;
	up_left.y = middle.y - wide;
	up_right.x = middle.x + wide;
	up_right.y = middle.y - wide;
	while (middle.y + wide >= up_left.y)
	{
		ft_bresenham(up_left, up_right, mlx, color);
		up_left.y = up_left.y + 1;
		up_right.y = up_right.y + 1;
	}
}

void	trace_path(t_list *path_list, t_mlx mlx, t_room *first)
{
	int		i;
	t_list	*path;

	path = NULL;
	i = 0;
	while (path_list)
	{
		path = path_list->content;
		if (i > 4)
			i = 0;
		ft_trace_path_color(first, path->content, mlx, &i);
		while (path->next)
		{
			ft_trace_path_color(path->content, path->next->content, mlx, &i);
			path = path->next;
		}
		i++;
		path_list = path_list->next;
	}
}

void	ft_trace_path_color(t_room *room1, t_room *room2, t_mlx mlx, int *i)
{
	static int	color[5] = {0x00FFFF, 0xFF00FF, 0x00FF00, 0x808000, 0xFFFF00};
	t_coord		start;
	t_coord		end;

	start.x = room1->x_coord;
	start.y = room1->y_coord;
	end.x = room2->x_coord;
	end.y = room2->y_coord;
	ft_bresenham(start, end, mlx, color[*i]);
}

void	trace_room(t_room *room, t_mlx mlx)
{
	t_coord	start;
	t_coord	end;
	int		i;

	while (room)
	{
		start.x = room->x_coord;
		start.y = room->y_coord;
		mlx_string_put(mlx.init, mlx.name,
			room->x_coord, room->y_coord - 50, 0xFFFFFF, room->name);
		i = 0;
		while (room->connection[i])
		{
			start.x = room->x_coord;
			start.y = room->y_coord;
			end.x = room->connection[i]->x_coord;
			end.y = room->connection[i]->y_coord;
			ft_bresenham(start, end, mlx, 0xFFFFFF);
			i++;
		}
		trace_square(start, 25, room->color, mlx);
		room = room->next;
	}
}
