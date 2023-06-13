/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:58:42 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/13 16:32:12 by amejia           ###   ########.fr       */
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
	t_vect	tmp;
	char	next_position;

	tmp.x = vars->char_pos.x;
	tmp.y = vars->char_pos.y;

	tmp.x = vars->char_pos.x;
	tmp.y = vars->char_pos.y;
	if (vars->char_pos.y < 1.0 && (move_to == 4))
		return ;
	if (vars->char_pos.x < 1.0 && (move_to == 1))
		return ;
	next_position = vars->map[(int)roundf(vars->char_pos.y)][(int)roundf(vars->char_pos.x)];
	if (next_position == '1')
		return ;
	if (move_to == 1)
		tmp = add_v(vars->char_pos, f_x_v(0.025, rotate_vector(vars->char_facing, -PI/2)));
	else if (move_to == 2)
		tmp = add_v(vars->char_pos, f_x_v(0.025, rotate_vector(vars->char_facing, PI/2)));
	else if (move_to == 3)
		tmp = add_v(vars->char_pos, f_x_v(0.025, rotate_vector(vars->char_facing, PI)));
	else if (move_to == 4)
		tmp = add_v(vars->char_pos, f_x_v(0.025, vars->char_facing));
	if (tmp.x < 0 || tmp.y < 0 || !vars->map[(int)roundf(tmp.y)][(int)roundf(tmp.x)])
		return ;
	next_position = vars->map[(int)roundf(tmp.y)][(int)roundf(tmp.x)];
	if (tmp.x < 1|| tmp.y < 1)
		return ;
	if (next_position == '1')
		return ;
	vars->map[(int)roundf(vars->char_pos.y)][(int)roundf(vars->char_pos.x)] = '0';
	vars->char_pos = tmp;
	put_minimap(vars);
}
