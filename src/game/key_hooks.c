/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 23:09:08 by mpizzolo         ###   ########.fr       */
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
	if (keycode == -1)
		return (0);
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

// int	key_actions(t_global *vars)
// {
// 	if (vars->key_a == 1)
// 		move_player(1, vars);
// 	return (0);
// }

int	key_press(int keycode, t_global *vars)
{
	vars->key_a = keycode;
	return (0);
}

int	key_released(int keycode, t_global *vars)
{
	vars->key_a = -1;
	return (0);
}

int	game_loop(void *param)
{
	t_global *vars;

	vars = (t_global *)param;
	// usleep(20000);
	key_hook(vars->key_a, vars);
	return (0);
}

int	initialize_key_hooks(t_global *vars)
{
	vars->mouse_pos = 1;
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_key_hook(vars->win, key_released, vars);
	mlx_loop_hook(vars->mlx, game_loop, (void *)vars);
	// mlx_key_hook(vars->win, key_hook, vars);
	// mlx_hook(vars->win, 6, 0, mouse_move, vars); 
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
	return (1);
}