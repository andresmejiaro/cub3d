/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:55:22 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 20:46:41 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int main(int argc, char *argv[])
{
	t_global	vars;	
	float	point[] = {0, 0};
	float	point2[] = {0, 1};
	float	point3[] = {1, 1};
	float	point4[] = {1, 1};
	float	*inter;

	inter = inter_lines(point, point2,point3,point4);
	



	if (!check_args(argc, argv[1]))
		return (1);
	if (!check_map(argv[1]))
		return (2);
	get_map(&vars, argv[1]);
	if (!start_map(&vars))
		return (3);
	return (0);
}
