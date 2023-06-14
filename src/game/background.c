/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:35:26 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/14 18:25:24 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	background(t_global *vars)
{
	t_image	img;
	int		x[2];
	int		n;
	int		c_color;
	int		f_color;

	img.img = mlx_new_image(vars->mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	c_color = create_trgb(0, vars->ceiling_color[0], vars->ceiling_color[1], vars->ceiling_color[2]);
	f_color = create_trgb(0, vars->floor_color[0], vars->floor_color[1], vars->floor_color[2]);
	ft_bzero(x, 2 * sizeof(int));
	while (++x[0] < SIZE_X)
	{
		x[1] = 0;
		while (++x[1] < (int)SIZE_Y)
		{
			if (x[1] > (int)SIZE_Y / 2)
				n  = f_color;
			else
				n = c_color;
			my_mlx_pixel_put(&img, x[0], x[1], n);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}
