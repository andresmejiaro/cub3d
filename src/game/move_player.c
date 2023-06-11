/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:58:42 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 21:02:37 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_left(t_global *vars)
{
	// if (matrix[(milei->y_pos / 50)][(milei->x_pos / 50) - 1] == 1)
	// 	return (0);
	// put_street(*vars, milei->x_pos, milei->y_pos);
	// matrix[(milei->y_pos / 50)][(milei->x_pos / 50) - 1] = 2;
	// milei->x_pos -= 50;
	// x = milei->x_pos;
	// y = milei->y_pos;
	put_minimap(vars);
}

void	move_player(int move_to, t_global *vars)
{
	int	moved;

	moved = 0;
	if (move_to == 1)
		move_left(vars);
	// else if (move_to == 2)
	// 	moved = move_right(milei, &g_vaars, matrix, map);
	// else if (move_to == 3)
	// 	moved = move_top(milei, &g_vaars, matrix, map);
	// else if (move_to == 4)
	// 	moved = move_bottom(milei, &g_vaars, matrix, map);
}
