/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:48:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/05 15:36:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0 && dst && src)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	if (src[i])
	{
		while (src[i])
			i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	z;
	size_t	dest_length;
	size_t	src_length;

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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)malloc(s1_size + s2_size + 1);
	if (!result)
		return (free(s1), NULL);
	if (s1)
		ft_strlcpy(result, s1, (s1_size + 1));
	free(s1);
	ft_strlcat(result, s2, s1_size + s2_size + 1);
	return (result);
}
