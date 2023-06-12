/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:57:38 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 14:32:43 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	*where_is_p(char **matrix)
{
	int	*p_pos;
	int	y;
	int	x;

	p_pos = (int *)malloc(2 * sizeof(int));
	if (!p_pos)
		return (0);
	y = 0;
	x = 0;
	while (matrix[y][x])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'N' || matrix[y][x] == 'E' || matrix[y][x] == 'S' || matrix[y][x] == 'W')
			{
				p_pos[0] = y;
				p_pos[1] = x;
				return (p_pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (p_pos);
}

void	put_facing(t_global *vars, int x, int y)
{
	if (vars->map[y][x] == 'N')	
	{	
		vars->char_facing[0] = y - 1;
		vars->char_facing[1] = x;
	}
	else if (vars->map[y][x] == 'S')
	{	
		vars->char_facing[0] = y + 1;
		vars->char_facing[1] = x;
	}
	else if (vars->map[y][x] == 'E')
	{	
		vars->char_facing[0] = y;
		vars->char_facing[1] = x - 1;
	}
	else if (vars->map[y][x] == 'W')
	{	
		vars->char_facing[0] = y;
		vars->char_facing[1] = x + 1;
	}
}

void	get_positions(t_global *vars)
{
	int		*p_pos;

	p_pos = where_is_p(vars->map);
	vars->char_pos[0] = p_pos[0];
	vars->char_pos[1] = p_pos[1];
	free(p_pos);
	put_facing(vars, vars->char_pos[1], vars->char_pos[0]);
}
