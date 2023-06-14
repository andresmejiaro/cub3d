/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:14:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/14 03:24:53 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub.h"

void	draw_circle(t_image *m_map, float centerX, float centerY, int radius, float scale, int color)
{
	float	scaled_centerx;
	float	scaled_center_y;
	float	x;
	float	y;
	float	radius_error;

	scaled_centerx = centerX * scale;
	scaled_center_y = centerY * scale;
	x = radius;
	y = 0;
	radius_error = 1 - x;
	while (x >= y)
	{
		my_mlx_pixel_put(m_map, scaled_centerx + x, scaled_center_y + y, color);
		my_mlx_pixel_put(m_map, scaled_centerx + y, scaled_center_y + x, color);
		my_mlx_pixel_put(m_map, scaled_centerx - y, scaled_center_y + x, color);
		my_mlx_pixel_put(m_map, scaled_centerx - x, scaled_center_y + y, color);
		my_mlx_pixel_put(m_map, scaled_centerx - x, scaled_center_y - y, color);
		my_mlx_pixel_put(m_map, scaled_centerx - y, scaled_center_y - x, color);
		my_mlx_pixel_put(m_map, scaled_centerx + y, scaled_center_y - x, color);
		my_mlx_pixel_put(m_map, scaled_centerx + x, scaled_center_y - y, color);
		y++;
		if (radius_error < 0)
		{
			radius_error += 2 * y + 1;
		}
		else
		{
			x--;
			radius_error += 2 * (y - x + 1);
		}
	}
}

void	draw_scaled_pixel(t_image *m_map, int x, int y, float scale, int color)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < scale)
	{
		dx = 0;
		while (dx < scale)
		{
			my_mlx_pixel_put(m_map, x * scale + dx, y * scale + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_line(t_global *vars, t_image *m_map, float x, float y, float scale, int color)
{
	float	dx;
	float	to_x;
	float	to_y;

	dx = 0;
	norm_vect(vars->char_facing);
	to_x = vars->char_facing.x;
	to_y = vars->char_facing.y;
	while (dx < 12 && dx >= 0)
	{
		my_mlx_pixel_put(m_map, (x * scale) + (dx * to_x),
			(y * scale) + (dx * to_y), color);
		dx += 0.25;
	}
}

void	scale_map(t_global *vars, t_image *m_map, int map_width)
{
	int		colors[2];
	float	scale;
	int		y;
	int		x;

	colors[0] = create_trgb(0, 132, 128, 128);
	colors[1] = create_trgb(0, 53, 48, 48);
	scale = vars->map_columns * 10 / map_width;
	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] != '0' && vars->map[y][x] != '1')
				draw_scaled_pixel(m_map, x, y, scale, colors[0]);
			if (vars->map[y][x] == '0')
				draw_scaled_pixel(m_map, x, y, scale, colors[0]);
			else if (vars->map[y][x] == '1')
				draw_scaled_pixel(m_map, x, y, scale, colors[1]);
		}
	}
	draw_line(vars, m_map, vars->char_pos.x, vars->char_pos.y, scale, 0x0000FF);
	draw_circle(m_map, vars->char_pos.x, vars->char_pos.y, 5, scale, 0xFF0000);
}
