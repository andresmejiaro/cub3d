/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:58:42 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 23:33:03 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void move_view(int view_to, t_global *vars)
{

	if (view_to == 2)
		vars->char_facing = rotate_vector(vars->char_facing, PI/8);
	else if (view_to == 1)	
		vars->char_facing = rotate_vector(vars->char_facing, -PI/8);
	put_minimap(vars);
}
	
void move_player(int move_to, t_global *vars)
{
	int		tmp_x;
	int		tmp_y;
	char	facing;
	char	next_position;

	tmp_x = (int)vars->char_pos.x;
	tmp_y = (int)vars->char_pos.y;
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
	facing = vars->map[(int)vars->char_pos.y][(int)vars->char_pos.x];
	vars->map[(int)vars->char_pos.y][(int)vars->char_pos.x] = '0';
	vars->map[tmp_y][tmp_x] = facing;
	vars->char_pos.x = tmp_x;
	vars->char_pos.y = tmp_y;
	put_minimap(vars);
}
