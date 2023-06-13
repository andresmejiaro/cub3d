/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:49:24 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/13 15:45:39 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	get_textures(t_global *vars, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line[0] == '\n')
		line = get_next_line(fd);
	while (line[0] != 'N')
		line++;
	vars->NO_texture = (t_image *)malloc(sizeof(t_image));
	vars->NO_texture->file = ft_strtrim((line + 3), "\n");
	vars->NO_texture->img = mlx_xpm_file_to_image(vars->mlx, vars->NO_texture->file, &vars->NO_texture->width, &vars->NO_texture->height);
	// vars->NO_texture->addr = mlx_get_data_addr(vars->NO_texture->img, &vars->NO_texture->bits_per_pixel, &vars->NO_texture->line_length, &vars->NO_texture->endian);
	line = get_next_line(fd);
	vars->SO_texture = (t_image *)malloc(sizeof(t_image));
	vars->SO_texture->file = ft_strtrim((line + 3), "\n");
	vars->SO_texture->img = mlx_xpm_file_to_image(vars->mlx, vars->SO_texture->file, &vars->SO_texture->width, &vars->SO_texture->height);
    // vars->SO_texture->addr = mlx_get_data_addr(vars->SO_texture->img, &vars->SO_texture->bits_per_pixel, &vars->SO_texture->line_length, &vars->SO_texture->endian);
	line = get_next_line(fd);
	vars->WE_texture = (t_image *)malloc(sizeof(t_image));
	vars->WE_texture->file = ft_strtrim((line + 3), "\n");
	vars->WE_texture->img = mlx_xpm_file_to_image(vars->mlx, vars->WE_texture->file, &vars->WE_texture->width, &vars->WE_texture->height);
    // vars->WE_texture->addr = mlx_get_data_addr(vars->WE_texture->img, &vars->WE_texture->bits_per_pixel, &vars->WE_texture->line_length, &vars->WE_texture->endian);
	line = get_next_line(fd);
	vars->EA_texture = (t_image *)malloc(sizeof(t_image));
	vars->EA_texture->file = ft_strtrim((line + 3), "\n");
	vars->EA_texture->img = mlx_xpm_file_to_image(vars->mlx, vars->EA_texture->file, &vars->EA_texture->width, &vars->EA_texture->height);
    // vars->EA_texture->addr = mlx_get_data_addr(vars->EA_texture->img, &vars->EA_texture->bits_per_pixel, &vars->EA_texture->line_length, &vars->EA_texture->endian);
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

void get_map_to_matrix(t_global *vars, size_t biggest_line_len, int rows, char *file)
{
	int	i;
	int	fd;
	char *line;

	vars->map_rows = rows;
	vars->map_columns = (int)biggest_line_len; 
	vars->map = (char **)malloc(sizeof(char *) * (rows + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (i++ < 7)
		line = get_next_line(fd);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		vars->map[i] = (char *)malloc(sizeof(char) * biggest_line_len + 1);
		ft_bzero(vars->map[i], biggest_line_len + 1);
		vars->map[i] = ft_strtrim(line, "\n");
		i++;
	}
	vars->map[rows] = NULL;
	close(fd);
}

void	get_map(t_global *vars, char *file)
{
	int		fd;
	char	*line;
	int		i;
	size_t	biggest_line_len;

	fd = open(file, O_RDONLY);
	get_textures(vars, fd);
	get_colors(vars, fd);
	i = 0;
	biggest_line_len = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) > biggest_line_len)
			biggest_line_len = ft_strlen(line);
		if (line != NULL)
			i++;
	}
	close(fd);
	get_map_to_matrix(vars, biggest_line_len, i, file);
}

