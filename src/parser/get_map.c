/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:49:24 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 14:19:53 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	get_textures(t_global *vars, int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	vars->NO_texture = ft_strtrim((line + 3), "\n");
	line = get_next_line(fd);
	vars->SO_texture = ft_strtrim((line + 3), "\n");
	line = get_next_line(fd);
	vars->WE_texture = ft_strtrim((line + 3), "\n");
	line = get_next_line(fd);
	vars->EA_texture = ft_strtrim((line + 3), "\n");
}

void	get_colors(t_global *vars, int fd)
{
	char	*line;
	char	**colors;

	line = get_next_line(fd);
	line = get_next_line(fd);
	line += 2;
	colors = ft_split(line, ',');
	vars->floor_color[0] = ft_atoi(colors[0]);
	vars->floor_color[1] = ft_atoi(colors[1]);
	vars->floor_color[2] = ft_atoi(colors[2]);
	line = get_next_line(fd);
	line += 2;
	colors = ft_split(line, ',');
	vars->ceiling_color[0] = ft_atoi(colors[0]);
	vars->ceiling_color[1] = ft_atoi(colors[1]);
	vars->ceiling_color[2] = ft_atoi(colors[2]);
}

void	get_map(t_global *vars, char *file)
{
	int		fd;
	char	*line;
	int		i;

	vars->map = (char **)malloc(sizeof(char *) * 100);
	fd = open(file, O_RDONLY);
	get_textures(vars, fd);
	get_colors(vars, fd);
	i = 0;
	vars->map[i] = (char *)malloc(sizeof(char) * 100);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		vars->map[i] = (char *)malloc(sizeof(char) * 100);
		vars->map[i] = line;
		i++;
	}
	vars->map[i] = NULL;
	close(fd);
}

