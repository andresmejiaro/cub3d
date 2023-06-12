/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 14:43:36 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	key_hook(int keycode, t_global *vars)
{

	if (keycode == 53)
		close_window(vars);
	else if (keycode == 13)
		move_player(4, vars);
	else if (keycode == 1)
		move_player(3, vars);
	else if (keycode == 2)
		move_player(2, vars);
	else if (keycode == 0)
		move_player(1, vars);
	else if (keycode == 124)
		move_view(1, vars);
	else if (keycode == 123)
		move_view(2, vars);
	return (0);
}

int	initialize_key_hooks(t_global *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	return (1);
}