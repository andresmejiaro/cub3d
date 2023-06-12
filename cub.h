/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:59:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 19:37:19 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define SIZE_X 1920
# define SIZE_Y 1080
# define PI 3.141592653589793238
# define KH_A 0
# define KH_W 13
# define KH_S 1
# define KH_D 2
# define KH_ESC 53
# define KH_LK 123
# define KH_RK 124
# define KH_SPACE 49

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>


typedef struct s_image {
	char	*file;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*pixels;
	int		size[2];
	int		pos[2];
	int		width;
	int		height;
}				t_image;

typedef struct s_global{
	void	*mlx;
	void	*win;
	char	**map;
	int		floor_color[3];
	int		ceiling_color[3];
	t_image	NO_texture;
	t_image	SO_texture;
	t_image	WE_texture;
	t_image	EA_texture;
	float	char_pos[2];
	float	char_facing[2];
	int long	mouse_pos;
}				t_global;

typedef struct s_text_param {
	char	*file;
	int		*position;
	int		column;
	int		size;	
}				t_text_param;

typedef struct s_color {
	int	t;
	int	r;
	int	g;
	int	b;
	int	trgb;
} t_color;

/*math*/
float dot_prod(float v1[2], float v2[2]);
float dist_vec(float v1[2], float v2[2]);
void rotate_vector(float *vec, float rad);
void	norm_vect(float *v1);
float *inter_lines(float orig1[2], float dir1[2], float orig2[2], float dir2[2]);
void rotate_vector(float *vec, float rad);

/* parser */
int		check_args(int argc, char *file);
int		check_map(char *file);
void	get_map(t_global *vars, char *file);
int		check_borders(char **matrix);

/* start map */
int		start_map(t_global *vars, char *argv);
void	get_positions(t_global *vars);

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

/* move player */
void	move_player(int move_to, t_global *vars);

/* move view */
void move_view(int view_to, t_global *vars);

/* render walls */
void    render_wall_col(t_global *vars, int column, int size, int *pos);

#endif