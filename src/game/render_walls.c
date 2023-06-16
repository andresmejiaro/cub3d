
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
	color->t = (unsigned char)p->n_wall->addr[((int)(y *ratio) 
		* p->n_wall->line_length) + 4 * p->column +  3];
	color->r = (unsigned char)p->n_wall->addr[((int)(y *ratio) 
		* p->n_wall->line_length) + 4 * p->column +  2];
	color->g = (unsigned char)p->n_wall->addr[((int)(y *ratio) 
		* p->n_wall->line_length) + 4 * p->column +  1];
	color->b = (unsigned char)p->n_wall->addr[((int)(y *ratio) 
		* p->n_wall->line_length) + 4 * p->column  ];
}


void    render_wall_col(t_global *vars, int column, int size, int *position, t_image *img)
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

	n_wall.img = mlx_xpm_file_to_image(vars->mlx, vars->no_texture->file, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	p.n_wall = &n_wall;
	ratio = (float)n_wall.height/size;
   	y = 0;
	while (y < size)
	{
		if (position[0] < 0 || position[0] >= SIZE_X)
			break ;
		if (position[1] + y < 0 || position[1] + y >= SIZE_Y)
		{
			y++;
			continue;
		}
		if (n_wall.endian == 1)
			endian1_color_asign(&color, &p, y ,ratio);
		else
			else_color_asign(&color, &p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(img, position[0], position[1] + y, color.trgb);
		y++;
	}
}


t_vect calc_ray_intersect(t_global *vars, int hor_pix, int *x_y)
{
	t_vect	posib[3];
	int		it;
	int		dir;
	float	pix_rot;


	if (hor_pix < 960)
		pix_rot = -atan((960 - hor_pix)/D_TO_SCREEN);
	else
		pix_rot = atan((hor_pix - 960)/D_TO_SCREEN);
	posib[2] = rotate_vector(vars->char_facing,pix_rot);
	//corte con x
	it = (int)floorf(vars->char_pos.x);
	dir = -1;
	if (posib[2].x == 0)
		posib[0] = set_vect(-1,-1);
	else
	{
		if (posib[2].x > 0)
		{
			dir  = 1;
			it++;
		}
		while( it > 0 && it < vars->map_columns)
		{
			posib[0] = inter_lines(vars->char_pos, posib[2], set_vect(it,0), set_vect(0,1));
			if (posib[0].y > 0 && posib[0].y < vars->map_rows && 
				vars->map[(int)floorf(posib[0].y)][it + (dir - 1)/2] == '1')
				break ;
			it += dir;
		}
		if (it == vars->map_columns || it == 0)
			posib[0] = set_vect(-1,-1);
	}
	//corrte con y
	it = (int)floorf(vars->char_pos.y);
	dir = -1;
	if (posib[2].y == 0)
		posib[1] = set_vect(-1,-1);
	else
	{
		if (posib[2].y > 0)
		{
			dir  = 1;
			it++;
		}
		while(it > 0 && it < vars->map_rows)
		{
			posib[1] = inter_lines(vars->char_pos, vars->char_facing, set_vect(0,it), set_vect(1,0));
			if (posib[1].y > 0 && posib[1].y < vars->map_rows && 
				vars->map[it + (dir - 1)/2][(int)floorf(posib[1].x)] == '1')
				break ;
			it += dir;
		}
		if (it == vars->map_rows || it == 0)
			posib[1] = set_vect(-1,-1);
	}

	*x_y = 1;
	if ( dist_vec(posib[0],set_vect(-1, -1)) == 0 && dist_vec(posib[1],set_vect(-1, -1)) == 0)
	{
		*x_y = -1;
		return (set_vect(-1,-1));
	}
	else if (dist_vec(posib[0],set_vect(-1, -1)) == 0 && dist_vec(posib[1],set_vect(-1, -1)) > 0)
		
		return (posib[1]);
	else if (dist_vec(posib[0],set_vect(-1, -1)) > 0 && dist_vec(posib[1],set_vect(-1, -1)) == 0)
	{
		*x_y = 0;
		return (posib[0]);
	}
	else if (dist_vec(posib[0],vars->char_pos) >  dist_vec(posib[1],vars->char_pos))
		return (posib[1]);
	else
	{
		*x_y = 0;
		return (posib[0]);
	}
}

// ct is 0 x_y es 1 por is 2
void mega_wall_render(t_global *vars, t_image *img)
{
	int ct[3];
	t_vect intersect;
	int pos[2];
	
	ft_bzero(ct, 3);
	while (ct[0] < SIZE_X)
	{
		intersect = calc_ray_intersect(vars, ct[0], &ct[1]);
		if (dist_vec(intersect, set_vect(-1,-1)) != 0)
		{
			pos[0] = ct[0];
			pos[1] = SIZE_Y / 2 - 500 / (dist_vec(vars->char_pos, 
				intersect) + 0.1);
			if (ct[1] == 0)
				ct[2] = (int)(50 * fmodf(intersect.x,1.0f));
			else if (ct[1] == 1)
				ct[2] = (int)(50 * fmodf(intersect.y,1.0f));
			if (ct[1] != -1)
				render_wall_col(vars, ct[2], 1000 / (dist_vec(vars->char_pos, 
					intersect) + 0.1), pos, img);
		}
		ct[0]++;
	}
}
