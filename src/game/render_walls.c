/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:58:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 22:09:14 by amejia           ###   ########.fr       */
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
	color->t = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  3];
	color->r = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  2];
	color->g = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  1];
	color->b = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column ];
}


void    render_wall_col(t_global *vars, t_wall_rend *p)
{
	t_image	mlx_n_image;
	t_color	color;
	int y;
	float ratio;

	ratio = (float)p->n_wall->height/p->size;
	mlx_n_image.img = mlx_new_image(vars->mlx,1,p->size);
	mlx_n_image.addr = mlx_get_data_addr(mlx_n_image.img,
		&mlx_n_image.bits_per_pixel, &mlx_n_image.line_length, &mlx_n_image.endian);
	y = 0;
	while (y < p->size)
	{
		if (p->n_wall->endian == 1)
			endian1_color_asign(&color, p, y, ratio);
		else
			else_color_asign(&color, p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(&mlx_n_image, 0, y, color.trgb);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, mlx_n_image.img, p->position[0],
		p->position[1]);
}

// void render_wall(t_global *vars,float *cor1, float *cor2, t_image *n_wall)
// {
// 	float		walldir[2];
// 	float		wallpos[2];
// 	float		current;
// 	t_wall_rend	p;
// 	float		vector2me[2];
// 	int count = 0;

// 	neg_v(cor1);
// 	add_v(cor2, cor1, walldir);
// 	current = 0;
// 	while (current < 1)
// 	{
// 		wallpos[0] = cor1[0] + current * walldir[0];
// 		wallpos[1] = cor1[1] + current * walldir[1];
// 		vector2me[0] = walldir[0] - vars->char_pos.y;
// 		vector2me[1] = walldir[1] - vars->char_pos.x;
// 		distance = dot_prod(vector2me, vars->char_facing);
		
// 		vector2me[0] -= distance * vars->char_facing.y;
// 		vector2me[1] -= distance * vars->char_facing.x;
// 		p.column = count;
// 		float z[2];
// 		ft_bzero(z, 2*sizeof(float));
// 		p.position[0] =  960 + dist_vec(vector2me,z);
// 		p.position[1] = 540;
// 		p.n_wall = n_wall;
// 		render_wall_col(vars,&p);
// 		current += STEP_S;
// 		count ++;
// 	}
	
// }