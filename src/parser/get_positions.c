/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:57:38 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 19:28:53 by mpizzolo         ###   ########.fr       */
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

void	put_facing(t_global *vars, char c)
{
	if (c == 'N')	
	{	
		vars->char_facing[0] = -1;
		vars->char_facing[1] = 0;
	}
	else if (c == 'S')
	{	
		vars->char_facing[0] = 1;
		vars->char_facing[1] = 0;
	}
	else if (c == 'E')
	{	
		vars->char_facing[0] = 0;
		vars->char_facing[1] = 1;
	}
	else if (c == 'W')
	{	
		vars->char_facing[0] = 0;
		vars->char_facing[1] = -1;
	}
}

void	get_positions(t_global *vars)
{
	int		*p_pos;

	p_pos = where_is_p(vars->map);
	vars->char_pos[0] = p_pos[0];
	vars->char_pos[1] = p_pos[1];
	free(p_pos);
	put_facing(vars, vars->map[(int)vars->char_pos[0]][(int)vars->char_pos[1]]);
}
