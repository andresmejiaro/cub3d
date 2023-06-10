/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:35:26 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 00:08:39 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	background(t_image img, int floor_col, int ceiling_col)
{
	int		x[2];
	int		n;
	
	ft_bzero(x, 2 * sizeof(int));
	while (++x[0] < SIZE_X)
	{
		x[1] = 0;
		while (++x[1] < (int)SIZE_Y)
		{
			if (x[1] > (int)SIZE_Y / 2)
				n  = floor_col;
			else
				n = ceiling_col;
			my_mlx_pixel_put(&img, x[0], x[1], n);
			
		}
	}
}