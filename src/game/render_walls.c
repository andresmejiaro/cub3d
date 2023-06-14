/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:58:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/14 20:54:01 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void endian1_color_asign(t_color *color, t_wall_rend *p, int y, float ratio)
{
	color->t = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column ];
	color->r = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column + 1];
	color->g = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column+ 2];
	color->b = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  3];
}


void else_color_asign(t_color *color, t_wall_rend *p, int y, float ratio)
{
	color->t = (unsigned char)p->n_wall->addr[((int)(y *ratio) * p->n_wall->line_length) + 4 * p->column +  3];
	color->r = (unsigned char)p->n_wall->addr[((int)(y *ratio) * p->n_wall->line_length) + 4 * p->column +  2];
	color->g = (unsigned char)p->n_wall->addr[((int)(y *ratio) * p->n_wall->line_length) + 4 * p->column +  1];
	color->b = (unsigned char)p->n_wall->addr[((int)(y *ratio) * p->n_wall->line_length) + 4 * p->column  ];
}


void    render_wall_col(t_global *vars, int column, int size, int *position)
{
	t_image	n_wall;
	t_image	mlx_n_image;
	t_color	color;
	int y;
	float ratio;
	t_wall_rend p;

	p.column = column;
	p.size = size;
	p.position[0] = position[0];
	p.position[1] = position[1];

	n_wall.img = mlx_xpm_file_to_image(vars->mlx, vars->NO_texture->file, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	p.n_wall = &n_wall;
	ratio = (float)n_wall.height/size;
	mlx_n_image.img = mlx_new_image(vars->mlx, 1, size);
	mlx_n_image.addr = mlx_get_data_addr(mlx_n_image.img, &mlx_n_image.bits_per_pixel, &mlx_n_image.line_length, &mlx_n_image.endian);
   	y = 0;
	while (y < size)
	{
		if (n_wall.endian == 1)
			endian1_color_asign(&color, &p, y ,ratio);
		else
			else_color_asign(&color, &p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(&mlx_n_image, 0, y, color.trgb);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, mlx_n_image.img, position[0], position[1]);
}


#if 0

void    render_wall_col_v2(t_global *vars, t_wall_rend p)
{
	t_image	n_wall;
	t_image	mlx_n_image;
	t_color	color;
	int y;
	float ratio;
	t_wall_rend p;

	p.column = column;
	p.size = size;
	p.position[0] = position[0];
	p.position[1] = position[1];

	n_wall.img = mlx_xpm_file_to_image(vars->mlx, vars->NO_texture->file, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	p.n_wall = &n_wall;
	ratio = (float)n_wall.height/size;
	mlx_n_image.img = mlx_new_image(vars->mlx, 1, size);
	mlx_n_image.addr = mlx_get_data_addr(mlx_n_image.img, &mlx_n_image.bits_per_pixel, &mlx_n_image.line_length, &mlx_n_image.endian);
   	y = 0;
	while (y < size)
	{
		if (n_wall.endian == 1)
			endian1_color_asign(&color, &p, y ,ratio);
		else
			else_color_asign(&color, &p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(&mlx_n_image, 0, y, color.trgb);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, mlx_n_image.img, position[0], position[1]);
}

#endif