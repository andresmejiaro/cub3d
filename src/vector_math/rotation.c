/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:37:05 by amejia            #+#    #+#             */
/*   Updated: 2023/06/12 00:37:11 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

// This function overwrites vec
void *rotate_vector(float *vec, float rad)
{
	float temp[2];

	temp[0] = cosf(rad) * vec[0] - sinf(rad) * vec[1];
	temp[1] = sinf(rad) * vec[0] + cosf(rad) * vec[1];
	vec[0] = temp[0];
	vec[1] = temp[1];	
}