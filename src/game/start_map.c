/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:40:53 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/14 20:02:16 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

// hay que  hacerlo de manera distinta
// la funcion put_tile esta comentada en mlx_utils.c
// int	put_walls(t_global *vars)
// {
// 	int size[2];
// 	int pos[2];
// 	pos[0] = (int)SIZE_X/2;
// 	pos[1] = (int)SIZE_Y/2;
// 	size[0] = 2000;
// 	size[1] = 2000;
// 	put_tile(vars, pos, size);
// 	return (1);
// }

void	start_keys(t_global *vars)
{
	vars->keys = (t_keys *)malloc(sizeof(t_keys));
	vars->keys->k_a = 0;
	vars->keys->k_w = 0;
	vars->keys->k_s = 0;
	vars->keys->k_d = 0;
	vars->keys->k_l = 0;
	vars->keys->k_r = 0;
	vars->keys->k_esc = 0;
	vars->keys->k_space = 0;
}

int	start_map(t_global *vars, char	*argv)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SIZE_X, SIZE_Y, "Cub3D");
	get_map(vars, argv);
	get_positions(vars);
	//background(vars);
	start_keys(vars);
	int pos[2];
	pos[0] = 500;
	pos[1] = 500;
	for (int i = 0; i<50; i++)
	{
		render_wall_col(vars,i,50 - i,pos);
		pos[0]++;
	}
	if (!put_minimap(vars))
		return (0);
	if (!initialize_key_hooks(vars))
		return (0);
	t_vect cor1 = set_vect(1,1);
	t_vect cor2 = set_vect(2, 1);
	t_image tmp;
	
	
	//tmp.img = mlx_xpm_file_to_image(vars->mlx, "/Users/amejia/cub3d/assets/wall_NO.xpm", &tmp.width, &tmp.height);
	//tmp.addr = mlx_get_data_addr(&tmp.img, &tmp.bits_per_pixel, &tmp.line_length, &tmp.endian);
	
	
	return (0);


	return (1);
}