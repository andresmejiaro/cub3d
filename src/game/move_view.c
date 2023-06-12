/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:09:15 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 17:00:48 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void move_view(int view_to, t_global *vars)
{

	if (view_to == 2)
		rotate_vector(vars->char_facing, PI/8);
	else if (view_to == 1)	
		rotate_vector(vars->char_facing, -PI/8);
	put_minimap(vars);
}