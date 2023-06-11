/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:58:42 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 22:53:11 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_left(t_global *vars)
{
	int		tmp;
	char	facing;
	
	if (vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1] - 1] == '1')
		return ;
	facing = vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]];
	tmp = (int)vars->char_pos[1];
	vars->char_pos[1] -= 1;
	vars->map[(int)vars->char_pos[0]][tmp] = '0';
	vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]] = facing;
	put_minimap(vars);
}

void	move_right(t_global *vars)
{
	int		tmp;
	char	facing;
	
	if (vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1] + 1] == '1')
		return ;
	facing = vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]];
	tmp = (int)vars->char_pos[1];
	vars->char_pos[1] += 1;
	vars->map[(int)vars->char_pos[0]][tmp] = '0';
	vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]] = facing;
	put_minimap(vars);
}

void	move_up(t_global *vars)
{
	int		tmp;
	char	facing;
	
	if (vars->map[(int)vars->char_pos[0] - 1][(int)vars->char_pos[1]] == '1')
		return ;
	facing = vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]];
	tmp = (int)vars->char_pos[0];
	vars->char_pos[0] -= 1;
	vars->map[tmp][(int)vars->char_pos[1]] = '0';
	vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]] = facing;
	put_minimap(vars);
}

void	move_bottom(t_global *vars)
{
	int		tmp;
	char	facing;
	
	if (vars->map[(int)vars->char_pos[0] + 1][(int)vars->char_pos[1]] == '1')
		return ;
	facing = vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]];
	tmp = (int)vars->char_pos[0];
	vars->char_pos[0] += 1;
	vars->map[tmp][(int)vars->char_pos[1]] = '0';
	vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]] = facing;
	put_minimap(vars);
}

void	move_player(int move_to, t_global *vars)
{
	if (move_to == 1)
		move_left(vars);
	else if (move_to == 2)
		move_right(vars);
	else if (move_to == 3)
		move_bottom(vars);
	else if (move_to == 4)
		move_up(vars);
}
