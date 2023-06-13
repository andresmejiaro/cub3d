/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:58:42 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/13 15:49:54 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void move_view(int view_to, t_global *vars)
{

	if (view_to == 2)
		vars->char_facing = rotate_vector(vars->char_facing, -PI/56);
	else if (view_to == 1)	
		vars->char_facing = rotate_vector(vars->char_facing, PI/56);
	put_minimap(vars);
}

void move_player(int move_to, t_global *vars)
{
	float	tmp_x;
	float	tmp_y;
	char	next_position;

	tmp_x = vars->char_pos.x;
	tmp_y = vars->char_pos.y;

	tmp_x = vars->char_pos.x;
	tmp_y = vars->char_pos.y;
	if (vars->char_pos.y < 1.0 && (move_to == 4))
		return ;
	if (vars->char_pos.x < 1.0 && (move_to == 1))
		return ;
	next_position = vars->map[(int)roundf(vars->char_pos.y)][(int)roundf(vars->char_pos.x)];
	if (next_position == '1')
		return ;
	if (move_to == 1)
		tmp_x -= 0.025;
	else if (move_to == 2)
		tmp_x += 0.025;
	else if (move_to == 3)
		tmp_y += 0.025;
	else if (move_to == 4)
		tmp_y -= 0.025;
	if (tmp_x < 0 || tmp_y < 0 || !vars->map[(int)roundf(tmp_y)][(int)roundf(tmp_x)])
		return ;
	next_position = vars->map[(int)roundf(tmp_y)][(int)roundf(tmp_x)];
	if (next_position == '1')
		return ;
	vars->map[(int)roundf(vars->char_pos.y)][(int)roundf(vars->char_pos.x)] = '0';
	vars->char_pos.x = tmp_x;
	vars->char_pos.y = tmp_y;
	put_minimap(vars);
}
