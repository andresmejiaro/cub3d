/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:10:27 by amejia            #+#    #+#             */
/*   Updated: 2023/06/13 15:08:23 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

float dot_prod(t_vect v1, t_vect v2)
{
	return(v1.x*v2.x + v1.y*v2.y);
}

// float dist_vec(t_vect v1[2], t_vect v2[2])
float dist_vec(t_vect v1, t_vect v2)
{
	float res;
	t_vect temp;
	
	temp = sub_v(v2, v1);
	res = sqrtf(dot_prod(temp, temp));
	return (res);
}

float size_vect(t_vect v)
{
	t_vect zero;

	zero.x = 0;
	zero.y = 0;
	return (dist_vec(v, zero));
}

t_vect norm_vect(t_vect v1)
{
	return (f_x_v(1/size_vect(v1), v1));
}

t_vect nearest_point(t_vect point, t_vect origin, t_vect director)
{
	t_vect segment;
	float proy;

	segment = sub_v(origin, point);
	director = norm_vect(director);
	proy = dot_prod(director, segment);
	segment = f_x_v(proy, director);
	segment = add_v(segment, point);
	return (segment);
}

t_vect set_vect(float x, float y)
{
	t_vect res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vect inter_lines(t_vect orig1, t_vect dir1, t_vect orig2, t_vect dir2)
{
	t_vect segment;
	float slope[2];
	
	slope[0]=dir1.y/dir1.x;
	slope[1]=dir2.y/dir2.x;
	if ((dir1.x == 0 && dir2.x == 0) || fabs(slope[0] - slope[1]) < 0.1)
		return (set_vect(INFINITY, INFINITY));
	if (dir1.x == 0)
	{
		segment.x = orig1.x;
		segment.y = slope[1]*(segment.x - orig2.x)+ orig2.y;
	}
	else if (dir2.x == 0)
	{
		segment.x = orig2.x;
		segment.y = slope[0]*(segment.x - orig1.x)+ orig1.y;
	}
	else
	{
		segment.y = ((-slope[0] / slope[1]) * orig2.y + slope[1] * orig2.x + orig1.y
			- slope[0] * orig1.x) / (1 - slope[0] / slope[1]);
		segment.x = (segment.y - orig1.y)/slope[0] + orig1.x;
	}
	return (segment);
}


