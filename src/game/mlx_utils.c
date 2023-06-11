/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:10:27 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 17:32:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
 	char	*dst;

 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
 	*(unsigned int*)dst = color;
}

int	close_window(t_global *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_FAILURE);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// t_image	ft_new_sprite(void *mlx, char *path, int *size)
// {
// 	t_image	img;

// 	img.img = mlx_xpm_file_to_image(mlx, path, &size[0], &size[1]);
// 	if (img.img == NULL)
// 		perror("Error\nImage failed to push to window");
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 			&img.line_length, &img.endian);
// 	return (img);
// }

// int	put_tile(t_global *vars, int* pos, int *size)
// {
// 	char	*relative_path;
// 	t_image	wall;
// 	int		fd;

// 	relative_path = "/Users/mpizzolo/Documents/cursus/cub3d/assets/Tile.xpm";
// 	fd = open(relative_path, O_RDONLY);
// 	if (fd < 0)
// 		return (perror("Error\nWall file could not be opened\n"), 1);
// 	close(fd);
// 	wall.size[0] = size[0];
// 	wall.size[1] = size[1];
// 	wall = ft_new_sprite(vars->mlx, relative_path, wall.size);
// 	wall.pos[0] = pos[0];
// 	wall.pos[1] = pos[1];
// 	mlx_put_image_to_window(vars->mlx, vars->win, wall.img, pos[0], pos[1]);
// 	return (0);
// }
