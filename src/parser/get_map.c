/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:49:24 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 22:34:32 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	get_textures(t_global *vars, int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	if (line[0] == '\n')
		line = get_next_line(fd);
	vars->NO_texture.file = ft_strtrim((line + 3), "\n");
	// vars->NO_texture.img = mlx_xpm_file_to_image(vars->mlx, vars->NO_texture.file, &vars->NO_texture.width, &vars->NO_texture.height);
	// vars->NO_texture.addr = mlx_get_data_addr(vars->NO_texture.img, &vars->NO_texture.bits_per_pixel, &vars->NO_texture.line_length, &vars->NO_texture.endian);
	line = get_next_line(fd);
	// vars->SO_texture.file = ft_strtrim((line + 3), "\n");
	// vars->SO_texture.img = mlx_xpm_file_to_image(vars->mlx, vars->SO_texture.file, &vars->SO_texture.width, &vars->SO_texture.height);
    // vars->SO_texture.addr = mlx_get_data_addr(vars->SO_texture.img, &vars->SO_texture.bits_per_pixel, &vars->SO_texture.line_length, &vars->SO_texture.endian);
	line = get_next_line(fd);
	// vars->WE_texture.file = ft_strtrim((line + 3), "\n");
	// vars->WE_texture.img = mlx_xpm_file_to_image(vars->mlx, vars->WE_texture.file, &vars->WE_texture.width, &vars->WE_texture.height);
    // vars->WE_texture.addr = mlx_get_data_addr(vars->WE_texture.img, &vars->WE_texture.bits_per_pixel, &vars->WE_texture.line_length, &vars->WE_texture.endian);
	line = get_next_line(fd);
	// vars->EA_texture.file = ft_strtrim((line + 3), "\n");
	// vars->EA_texture.img = mlx_xpm_file_to_image(vars->mlx, vars->EA_texture.file, &vars->EA_texture.width, &vars->EA_texture.height);
    // vars->EA_texture.addr = mlx_get_data_addr(vars->EA_texture.img, &vars->EA_texture.bits_per_pixel, &vars->EA_texture.line_length, &vars->EA_texture.endian);
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

