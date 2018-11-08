/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_bresenham.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:57:48 by rfibigr           #+#    #+#             */
/*   Updated: 2018/11/08 19:38:04 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_bresenham(t_coord initial, t_coord final, t_mlx window, int color)
{
	t_line	line;

	line.xsign = 1;
	line.ysign = 1;
	line.x1 = initial.x;
	line.x2 = final.x;
	line.y1 = initial.y;
	line.y2 = final.y;
	line.ex = ft_abs(line.x2 - line.x1);
	line.ey = ft_abs(line.y2 - line.y1);
	line.dy_i = line.ey;
	line.dx_i = line.ex;
	line.dy = 2 * line.ey;
	line.dx = 2 * line.ex;
	if (line.y1 > line.y2)
		line.ysign = -1;
	if (line.x1 > line.x2)
		line.xsign = -1;
	if (line.dx_i > line.dy_i)
		ft_x_inc(line, window, color);
	else
		ft_y_inc(line, window, color);
}

void	ft_x_inc(t_line line, t_mlx window, int color)
{
	int i;

	i = 0;
	while (i <= line.dx_i)
	{
		mlx_pixel_put(window.init, window.name, line.x1, line.y1, color);
		i++;
		line.x1 += line.xsign;
		line.ex -= line.dy;
		if (line.ex < 0)
		{
			line.y1 += line.ysign;
			line.ex += line.dx;
		}
	}
}

void	ft_y_inc(t_line line, t_mlx window, int color)
{
	int i;

	i = 0;
	while (i <= line.dy_i)
	{
		mlx_pixel_put(window.init, window.name, line.x1, line.y1, color);
		i++;
		line.y1 += line.ysign;
		line.ey -= line.dx;
		if (line.ey < 0)
		{
			line.x1 += line.xsign;
			line.ey += line.dy;
		}
	}
}
