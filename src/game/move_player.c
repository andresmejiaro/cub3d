/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:58:42 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 15:03:28 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void move_player(int move_to, t_global *vars)
{
	int		tmp_x;
	int		tmp_y;
	char	facing;
	char	next_position;

	tmp_x = (int)vars->char_pos[1];
	tmp_y = (int)vars->char_pos[0];
	if (move_to == 1)
		tmp_x -= 1;
	else if (move_to == 2)	
		tmp_x += 1;
	else if (move_to == 3)	
		tmp_y += 1;
	else if (move_to == 4)	
		tmp_y -= 1;
	if (tmp_x < 0 || tmp_y < 0 || !vars->map[tmp_y][tmp_x])
		return ;
	next_position = vars->map[tmp_y][tmp_x];
	if (next_position == '1')
		return ;
	facing = vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]];
	vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]] = '0';
	vars->map[tmp_y][tmp_x] = facing;
	vars->char_pos[1] = tmp_x;
	vars->char_pos[0] = tmp_y;
	put_minimap(vars);
}
