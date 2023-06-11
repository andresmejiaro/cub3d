/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:40:53 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 20:50:45 by amejia           ###   ########.fr       */
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

int	start_map(t_global *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SIZE_X, SIZE_Y, "Cub3D");
	background(vars);
	// if (!put_minimap(vars))
	// 	return (0);
	if (!initialize_key_hooks(vars))
		return (0);
	// if (!put_walls(vars))
	// 	return (0);
	mlx_loop(vars->mlx);
	return (1);
}