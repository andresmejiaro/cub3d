/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:55:22 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 20:47:47 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int main(int argc, char *argv[])
{
	t_global	vars;	
		
	if (!check_args(argc, argv[1]))
		return (1);
	if (!check_map(argv[1]))
		return (2);
	if (!start_map(&vars, argv[1]))
		return (3);
	return (0);
}
