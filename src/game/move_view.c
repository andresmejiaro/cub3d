/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:09:15 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 14:20:53 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void move_view(int view_to, t_global *vars)
{
	int		tmp_x;

	tmp_x = (int)vars->char_facing[1];
	if (view_to == 2)
		tmp_x -= 1;
	else if (view_to == 1)	
		tmp_x += 1;
	vars->char_facing[1] = tmp_x;
	put_minimap(vars);
}