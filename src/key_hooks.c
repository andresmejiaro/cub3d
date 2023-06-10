/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:11:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 00:04:06 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	key_hook(int keycode, t_global *vars)
{

	if (keycode == 53)
		close_window(vars);
	return (0);
}

int	initialize_key_hooks(t_global *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	return (1);
}