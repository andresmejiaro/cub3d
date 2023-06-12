/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:05:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 22:45:48 by mpizzolo         ###   ########.fr       */
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

void calculate_map_dimensions(t_global *vars, int *map_width, int *map_height)
{
	*map_width = 0;
	*map_height = 0;

	while (vars->map[*map_height])
	{
		int current_row_width = 0;
		while (vars->map[*map_height][current_row_width] && vars->map[*map_height][current_row_width] != '\n')
			current_row_width++;
		if (current_row_width > *map_width)
			*map_width = current_row_width;
		(*map_height)++;
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
	float	to_x = vars->char_facing.y;
	float	to_y = vars->char_facing.x;
	
	while (dx < 38)
	{
		my_mlx_pixel_put(m_map, (x * scale) + (dx * to_x), (y * scale) + (dx * to_y), color);
		dx += 0.25;
	}
}


void scale_minimap(t_global *vars, t_image *m_map, int map_width)
{
	int colors[2];
	colors[0] = create_trgb(0, 255, 255, 255);
	colors[1] = create_trgb(0, 0, 0, 0);

	float scale = 250.0 / map_width; // Calculate the scale factor based on the map's width

	int y = -1;
	while (vars->map[++y])
	{
		int x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] != '0' && vars->map[y][x] != '1' && vars->map[y][x] != '\n')
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
		draw_line(vars, m_map, vars->char_pos.x + 0.485, vars->char_pos.y + 0.485, scale, 0x0000FF);
		draw_circle(m_map, vars->char_pos.x + 0.485, vars->char_pos.y + 0.485, 5, scale, 0xFF0000);
	// }
}

int put_minimap(t_global *vars)
{
	t_image m_map;
	int map_width;
	int map_height;

	m_map.img = mlx_new_image(vars->mlx, 250, 250);
	m_map.addr = mlx_get_data_addr(m_map.img, &m_map.bits_per_pixel, &m_map.line_length, &m_map.endian);
	calculate_map_dimensions(vars, &map_width, &map_height);
	scale_minimap(vars, &m_map, map_width);
	mlx_put_image_to_window(vars->mlx, vars->win, m_map.img, 0, 0);
	return (1);
}