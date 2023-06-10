/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:59:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/10 20:36:45 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct m_map {
	int	is_player;
// ...
}				t_map;


#endif