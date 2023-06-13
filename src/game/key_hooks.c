/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/13 17:40:58 by amejia           ###   ########.fr       */
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

int	key_actions(t_global *vars)
{
	if (vars->keys->k_esc == 1)
		close_window(vars);
	else if (vars->keys->k_w == 1)
		move_player(4, vars);
	else if (vars->keys->k_s == 1)
		move_player(3, vars);
	else if (vars->keys->k_d == 1)
		move_player(2, vars);
	else if (vars->keys->k_a == 1)
		move_player(1, vars);
	else if (vars->keys->k_r == 1)
		move_view(1, vars);
	else if (vars->keys->k_l == 1)
		move_view(2, vars);
	// else if (vars->keys->k_space == 1)
	// 	open_door()
	return (0);
}

int	key_press(int keycode, t_global *vars)
{
	if (keycode == KH_ESC)
		vars->keys->k_esc = 1;
	else if (keycode == KH_W)
		vars->keys->k_w = 1;
	else if (keycode == KH_S)
		vars->keys->k_s = 1;
	else if (keycode == KH_D)
		vars->keys->k_d = 1;
	else if (keycode == KH_A)
		vars->keys->k_a = 1;
	else if (keycode == KH_RK)
		vars->keys->k_r = 1;
	else if (keycode == KH_LK)
		vars->keys->k_l = 1;
	else if (keycode == KH_SPACE)
		vars->keys->k_space = 1;
	return (0);
}

int	key_released(int keycode, t_global *vars)
{
	if (keycode == KH_ESC)
		vars->keys->k_esc = 0;
	else if (keycode == KH_W)
		vars->keys->k_w = 0;
	else if (keycode == KH_S)
		vars->keys->k_s = 0;
	else if (keycode == KH_D)
		vars->keys->k_d = 0;
	else if (keycode == KH_A)
		vars->keys->k_a = 0;
	else if (keycode == KH_RK)
		vars->keys->k_r = 0;
	else if (keycode == KH_LK)
		vars->keys->k_l = 0;
	else if (keycode == KH_SPACE)
		vars->keys->k_space = 0;
	return (0);
}

int	game_loop(void *param)
{
	t_global *vars;

	vars = (t_global *)param;
	key_actions(vars);
	t_vect cor1 = set_vect(1,1);
	t_vect cor2 = set_vect(2, 1);
	t_image tmp;
	
	
	tmp.img = mlx_xpm_file_to_image(vars->mlx, "/Users/amejia/cub3d/assets/wall_NO.xpm", &tmp.width, &tmp.height);
	tmp.addr = mlx_get_data_addr(&tmp.img, &tmp.bits_per_pixel, &tmp.line_length, &tmp.endian);
	render_wall(vars, cor1, cor2, &tmp);
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