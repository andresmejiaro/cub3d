/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:10:27 by amejia            #+#    #+#             */
/*   Updated: 2023/06/11 22:48:33 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

float dot_prod(float v1[2], float v2[2])
{
	return (v1[0]*v2[0] + v1[1]*v2[1]);
}


float dist_vec(float v1[2], float v2[2])
{
	float v3[2];
	
	v3[0] = v1[0] -v2[0];
	v3[1] = v1[1] -v2[1];
	return (sqrtf(dot_prod(v3,v3)));
}


void norm_vect(float *v1)
{
	float size;
	float zerov[2];

	ft_bzero(zerov,2 * sizeof(float));
	size = dist_vec(v1,zerov);
	v1[0] = v1[0]/size;
	v1[1] = v1[1]/size;
}

float *nearest_point(float orig1[2], float dir1[2], float orig2[2], float dir2[2])
{
	float *segment;
	float proy;

	segment = ft_calloc(2 , sizeof(float));
	segment[0] = orig2[0] - orig1[0]; 
	segment[1] = orig2[1] - orig1[1]; 
	norm_vect(dir2); 
	if (fabs(dir1[1]/dir1[0] - dir2[1]/dir2[0]) < 0.1)
		return (NULL);
	proy = dot_prod(dir2, segment);
	segment[0] = proy * dir2[0];
	segment[1] = proy * dir2[1];
	segment[0] = segment[0] + orig1[0];
	segment[1] = segment[1] + orig1[1];
	return (segment);	
}


float *inter_lines(float orig1[2], float dir1[2], float orig2[2], float dir2[2])
{
	float *segment;
	float slope[2];

	slope[0]=dir1[1]/dir1[0];
	slope[1]=dir2[1]/dir2[0];
	if (fabs(slope[0] - slope[1]) < 0.1)
		return (NULL);

	segment = ft_calloc(2 , sizeof(float));
	segment[1] = ((-slope[0] / slope[1]) * orig2[1] + slope[1] * orig2[0] + orig1[1]
		- slope[0] * orig1[0]) / (1 - slope[0] / slope[1]);
	segment[0] = (segment[1] - orig1[1])/slope[0] + orig1[0];
	return (segment);	
}
