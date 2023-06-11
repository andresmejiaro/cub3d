/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:58:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 20:54:03 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void    render_wall_col(t_global *vars, int column, int size, int *position)
{
	t_image	n_wall;
	t_image	mlx_n_image;
	t_color	color;
	int y;
	float ratio;

	n_wall.img = mlx_xpm_file_to_image(vars->mlx, vars->NO_texture.file, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	ratio = (float)n_wall.height/size;
	mlx_n_image.img = mlx_new_image(vars->mlx, 1, size);
	mlx_n_image.addr = mlx_get_data_addr(mlx_n_image.img, &mlx_n_image.bits_per_pixel, &mlx_n_image.line_length, &mlx_n_image.endian);
   
	// while (x < n_wall.width* 4)
	// {
   	y = 0;
	while (y < size)
	{
		if (n_wall.endian == 1)
		{
			color.t = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column ];
			color.r = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column + 1];
			color.g = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column+ 2];
			color.b = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  3];
		}
		else
		{
			color.t = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  3];
			color.r = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  2];
			color.g = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  1];
			color.b = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column ];
		}
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(&mlx_n_image, 0, y, color.trgb);
		y++;
	}
	//	posx++;
	//	x+= 4;
	// }
	mlx_put_image_to_window(vars->mlx, vars->win, mlx_n_image.img, position[0], position[1]);
}