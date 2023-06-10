/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:01:20 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	z;
	unsigned int	dest_length;
	unsigned int	src_length;

	if (dst == '\0')
		dest_length = 0;
	else
		dest_length = ft_strlen(dst);
	z = dest_length;
	src_length = ft_strlen(src);
	if (dstsize <= dest_length || dstsize == 0)
		return (src_length + dstsize);
	i = 0;
	while (i < (dstsize - z - 1) && src[i] && z + 1 < dstsize)
	{
		dst[z + i] = src[i];
		i++;
	}		
	dst[z + i] = '\0';
	return (dest_length + src_length);
}
