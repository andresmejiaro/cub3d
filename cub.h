/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:59:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 20:46:41 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define SIZE_X 1920
# define SIZE_Y 1080

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_global{
	void	*mlx;
	void	*win;
	char	**map;
	int		floor_color[3];
	int		ceiling_color[3];
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	float	char_pos[2];
	float	char_facing[2];
}				t_global;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*pixels;
	int		size[2];
	int		pos[2];
}				t_image;


/*math*/
float dot_prod(float v1[2], float v2[2]);
float dist_vec(float v1[2], float v2[2]);
float norm_vec(float v1[2], float v2[2]);
float *inter_lines(float orig1[2], float dir1[2], float orig2[2], float dir2[2]);


/* parser */
int		check_args(int argc, char *file);
int		check_map(char *file);
void	get_map(t_global *vars, char *file);
int		is_playable(int fd);
int		check_borders(char **matrix);

/* start map */
int		start_map(t_global *vars);

/* key hooks */
int		initialize_key_hooks(t_global *vars);

/* mlx utils */
int		close_window(t_global *vars);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

/* background */
void	background(t_global *vars);

/* minimap */
int		put_minimap(t_global *vars);

#endif