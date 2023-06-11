/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:57:38 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 22:44:01 by mpizzolo         ###   ########.fr       */
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
	while (matrix[y][x] )
	{
		x = 0;
		while (matrix[y][x] )
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

int p_if_possible(int y, int x, char **matrix)
{
	if (y < 0 || x < 0)
		return (0);
	if (matrix[y][x] && (matrix[y][x] == '0' || matrix[y][x] == 'N' || matrix[y][x] == 'E' || matrix[y][x] == 'S' || matrix[y][x] == 'W'))
		matrix[y][x] = '2';
	else
		return (0);
	return 1;
}


void	explore_board(int *p_pos, char **matrix)
{
	if (p_if_possible(p_pos[0] - 1, p_pos[1], matrix))
	{
		p_pos[0] -= 1;
		explore_board(p_pos, matrix);
		p_pos[0] += 1;
	}
	if (p_if_possible(p_pos[0] + 1, p_pos[1], matrix))
	{
		p_pos[0] += 1;
		explore_board(p_pos, matrix);
		p_pos[0] -= 1;
	}
	if (p_if_possible(p_pos[0], p_pos[1] - 1, matrix))
	{
		p_pos[1] -= 1;
		explore_board(p_pos, matrix);
		p_pos[1] += 1;
	}
	if (p_if_possible(p_pos[0], p_pos[1] + 1, matrix))
	{
		p_pos[1] += 1;
		explore_board(p_pos, matrix);
		p_pos[1] -= 1;
	}
}

char	**start_matrix(int fd)
{
	char	**matrix;
	int		i;
	char	*line;

	matrix = (char **)malloc(sizeof(char *) * 100);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		matrix[i] = (char *)malloc(sizeof(char) * 100);
		matrix[i] = line;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int	is_playable(t_global *vars, int fd)
{
	char	**matrix;
	int		*p_pos;

	matrix = start_matrix(fd);
	p_pos = where_is_p(matrix);
	vars->char_pos[0] = p_pos[0];
	vars->char_pos[1] = p_pos[1];
	explore_board(p_pos, matrix);
	free(p_pos);
	// check_borders(matrix);
	return (1);
}
