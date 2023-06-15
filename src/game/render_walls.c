
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

	n_wall.img = mlx_xpm_file_to_image(vars->mlx, vars->no_texture->file, &n_wall.width, &n_wall.height);
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

// wall contains director in 0, current position in 1 and direct ffrom player in 2
void render_wall(t_global *vars,t_vect cor1, t_vect cor2, t_image *n_wall)
{
	t_vect wall[3];
	t_wall_rend	p;
	int count;
	float theta[3]; // 0 es min 1 es max 2 es working;
	
	theta[0] = vec_angle(vars->char_facing, sub_v(cor1,vars->char_pos));
	theta[1] = vec_angle(vars->char_facing, sub_v(cor2,vars->char_pos));
	if (theta[1] < theta[0]){
		theta[2] = theta[0];
		theta[0] = theta[1];
		theta[1] = theta[2];
		wall[0] = cor1;
		cor1 = cor2;
		cor2 = wall[0];
	}
	wall[0] = sub_v(cor2, cor1); // director vector of wall.
	count = 0;
	while (count < 1920)
	{
		theta[2] = atanf((-960 + count)/D_TO_SCREEN);
		if (theta[2] < theta[0] || theta[2] > theta[1])
			continue ;
		wall[1] = inter_lines(vars->char_pos,rotate_vector(vars->char_facing,theta[2]), cor1,wall[0]);		
		p.column = (int) 50 * dist_vec(wall[1], cor1) / dist_vec(cor1,cor2);
		p.position[0] = count;
		p.n_wall = n_wall;
		p.size = SIZEC / (dist_vec(vars->char_pos, wall[1]) + 1);
		p.position[1] = 540 - p.size / 2;
		render_wall_col(vars,p.column, p.size, p.position);
		count ++;
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


void mega_wall_render(t_global *vars)
{
	int ct;
	t_vect intersect;
	int pos[2];
	int x_y;
	int por;

	ct = 0;
	while (ct < SIZE_X)
	{
		x_y = -1;
		intersect = calc_ray_intersect(vars, ct, &x_y);
		if (dist_vec(intersect, set_vect(-1,-1)) != 0)
		{
			pos[0] = ct;
			pos[1] = SIZE_Y / 2 - 500 / (dist_vec(vars->char_pos, intersect) + 0.1);
			if (x_y == 0)
				por = (int)(50 * floorf(intersect.x));
			else if (x_y == 1)
				por = (int)(50 * floorf(intersect.y));
			else
			{
				ct++;
				continue ;
			}
			render_wall_col(vars, por, 1000 / (dist_vec(vars->char_pos, intersect) + 0.1), pos);
		}
		ct++;
	}
}