/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:55:22 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 00:28:00 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int main(int argc, char *argv[])
{
	t_global	vars;
	t_image	img;
	
		
	if (!check_args(argc, argv[1]))
		return (1);
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIZE_X, SIZE_Y, "Cub3D");
	
	img.img = mlx_new_image(vars.mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	background(img, create_trgb(0, 220, 100, 0), create_trgb(0, 225, 30, 0));
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	
	int size[2];
	int pos[2];
	pos[0] = (int)SIZE_X/2;
	pos[1] = (int)SIZE_Y/2;
	size[0] = 2000;
	size[1] = 2000;
	put_tile(&vars, pos, size);
	if (!initialize_key_hooks(&vars))
		return (2);
	mlx_loop(vars.mlx);
}
