/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:39:12 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/12 16:42:30 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

// This function overwrites vec
void rotate_vector(float *vec, float rad)
{
	float temp[2];

	temp[0] = cosf(rad) * vec[0] - sinf(rad) * vec[1];
	temp[1] = sinf(rad) * vec[0] + cosf(rad) * vec[1];
	vec[0] = temp[0];
	vec[1] = temp[1];	
}
