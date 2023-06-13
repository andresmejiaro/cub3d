/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:05:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/13 16:02:33 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void draw_circle(t_image *m_map, float centerX, float centerY, int radius, float scale, int color)
{
	float scaledCenterX = centerX * scale;
    float scaledCenterY = centerY * scale;
	float x = radius;
	float y = 0;
	float radiusError = 1 - x;

	while (x >= y)
	{
		my_mlx_pixel_put(m_map, scaledCenterX + x, scaledCenterY + y, color);
		my_mlx_pixel_put(m_map, scaledCenterX + y, scaledCenterY + x, color);
		my_mlx_pixel_put(m_map, scaledCenterX - y, scaledCenterY + x, color);
		my_mlx_pixel_put(m_map, scaledCenterX - x, scaledCenterY + y, color);
		my_mlx_pixel_put(m_map, scaledCenterX - x, scaledCenterY - y, color);
		my_mlx_pixel_put(m_map, scaledCenterX - y, scaledCenterY - x, color);
		my_mlx_pixel_put(m_map, scaledCenterX + y, scaledCenterY - x, color);
		my_mlx_pixel_put(m_map, scaledCenterX + x, scaledCenterY - y, color);

		y++;

		if (radiusError < 0)
		{
			radiusError += 2 * y + 1;
		}
		else
		{
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}

void draw_scaled_pixel(t_image *m_map, int x, int y, float scale, int color)
{
	int dy = 0;
	while (dy < scale) // Loop over scaled y-coordinates
	{
		int dx = 0;
		while (dx < scale) // Loop over scaled x-coordinates
		{
			my_mlx_pixel_put(m_map, x * scale + dx, y * scale + dy, color);
			dx++;
		}
		dy++;
	}
}

void draw_line(t_global *vars, t_image *m_map, float x, float y, float scale, int color)
{
	float dx = 0;
	norm_vect(vars->char_facing);
	float	to_x = vars->char_facing.x;
	float	to_y = vars->char_facing.y;
	
	while (dx < 12 && dx >= 0)
	{
		my_mlx_pixel_put(m_map, (x * scale) + (dx * to_x), (y * scale) + (dx * to_y), color);
		dx += 0.25;
	}
}


void scale_minimap(t_global *vars, t_image *m_map, int map_width)
{
	int colors[2];
	colors[0] = create_trgb(0, 132, 128, 128);
	colors[1] = create_trgb(0, 53, 48, 48);

	float scale = 135.0 / map_width; // Calculate the scale factor based on the map's width

	int y = -1;
	while (vars->map[++y])
	{
		int x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] != '0' && vars->map[y][x] != '1')
			{	
				draw_scaled_pixel(m_map, x, y, scale, colors[0]);
				// draw_line(vars, m_map, x + 0.485, y + 0.485, scale, 0x0000FF);
				// draw_circle(m_map, x + 0.485, y + 0.485, 5, scale, 0xFF0000);
			}
			if (vars->map[y][x] == '0')
				draw_scaled_pixel(m_map, x, y, scale, colors[0]);
			else if (vars->map[y][x] == '1')
				draw_scaled_pixel(m_map, x, y, scale, colors[1]);
		}
	}
	// if (vars->map[(int)roundf(vars->char_pos.y)][(int)roundf(vars->char_pos.x)] != '1')
	// {
		draw_line(vars, m_map, vars->char_pos.x, vars->char_pos.y, scale, 0x0000FF);
		draw_circle(m_map, vars->char_pos.x, vars->char_pos.y, 5, scale, 0xFF0000);
	// }
}

int put_minimap(t_global *vars)
{
	t_image m_map;
	// t_image frame;

	m_map.img = mlx_new_image(vars->mlx, 135, 135);
	m_map.addr = mlx_get_data_addr(m_map.img, &m_map.bits_per_pixel, &m_map.line_length, &m_map.endian);
	scale_minimap(vars, &m_map, vars->map_columns);
	mlx_put_image_to_window(vars->mlx, vars->win, m_map.img, 0, 0);
	// frame.img = mlx_xpm_file_to_image(vars->mlx, "./assets/frame.xpm", &frame.width, &frame.height);
	// frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
	// mlx_put_image_to_window(vars->mlx, vars->win, frame.img, 0, 0);
	return (1);
}