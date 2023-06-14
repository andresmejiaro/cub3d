
#include "../../cub.h"

void	get_textures(t_global *vars, int fd)
{
	char	*line;
	t_image	*tmp;
	
	line = get_next_line(fd);
	if (line[0] == '\n')
		line = get_next_line(fd);
	while (line[0] != 'N')
		line++;
	tmp = (t_image *)malloc(sizeof(t_image));
	tmp->file = ft_strtrim((line + 3), "\n");
	tmp->img = mlx_xpm_file_to_image(vars->mlx, tmp->file, &tmp->width, &tmp->height);
	// tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel, &tmp->line_length, &tmp->endian);
	vars->no_texture = tmp;
	line = get_next_line(fd);
	tmp->file = ft_strtrim((line + 3), "\n");
	tmp->img = mlx_xpm_file_to_image(vars->mlx, tmp->file, &tmp->width, &tmp->height);
	// tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel, &tmp->line_length, &tmp->endian);
	vars->so_texture = tmp;
	line = get_next_line(fd);
	tmp->file = ft_strtrim((line + 3), "\n");
	tmp->img = mlx_xpm_file_to_image(vars->mlx, tmp->file, &tmp->width, &tmp->height);
	// tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel, &tmp->line_length, &tmp->endian);
	vars->we_texture = tmp;
	line = get_next_line(fd);
	tmp->file = ft_strtrim((line + 3), "\n");
	tmp->img = mlx_xpm_file_to_image(vars->mlx, tmp->file, &tmp->width, &tmp->height);
	// tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel, &tmp->line_length, &tmp->endian);
	vars->ea_texture = tmp;
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

void	put_ones_on_str(char *str, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		if (str[i] == ' ' || (str[i] != '0' && str[i] != 'N' && str[i] != 'S'
				&& str[i] != 'E' && str[i] != 'W'))
			str[i] = '1';
	}
	str[i] = '\0';
}

void get_map_to_matrix(t_global *vars, size_t biggest_line_len, int rows, char *file)
{
	int		i;
	int		x;
	int		fd;
	char	*line;

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
		line = ft_strtrim(line, "\n");
		x = -1;
		while (line[++x] && line[x] != '\n')
			vars->map[i][x] = line[x];
		put_ones_on_str(vars->map[i], biggest_line_len);
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
		line = ft_strtrim(line, "\n");
		if (ft_strlen(line) > biggest_line_len)
			biggest_line_len = ft_strlen(line);
		if (line != NULL)
		{	
			free(line);
			i++;
		}
	}
	close(fd);
	get_map_to_matrix(vars, biggest_line_len, i, file);
}
