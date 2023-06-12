/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 19:37:28 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"


int	mouse_move(int keycode, t_global *vars)
{
	if (vars->mouse_pos - keycode > 100)
	{
		vars->mouse_pos = keycode;
		printf("keycode: %i\n", keycode);
	}
	return 0;	
}

int	key_hook(int keycode, t_global *vars)
{
	if (keycode == KH_ESC)
		close_window(vars);
	else if (keycode == KH_W)
		move_player(4, vars);
	else if (keycode == KH_S)
		move_player(3, vars);
	else if (keycode == KH_D)
		move_player(2, vars);
	else if (keycode == KH_A)
		move_player(1, vars);
	else if (keycode == KH_RK)
		move_view(1, vars);
	else if (keycode == KH_LK)
		move_view(2, vars);
	// else if (keycode == KH_SPACE)
	// 	open_door()
	return (0);
}

int	initialize_key_hooks(t_global *vars)
{
	vars->mouse_pos = 1;
	mlx_key_hook(vars->win, key_hook, vars);
	// mlx_hook(vars->win, 6, 0, mouse_move, vars); 
	mlx_hook(vars->win, 17, 0, close_window, vars);
	return (1);
}