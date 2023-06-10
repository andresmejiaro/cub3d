/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:23:30 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	z;
	char	*result;

	i = 0;
	if ((haystack && needle[0] == '\0'))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len && haystack)
	{
		z = 0;
		while (haystack[i + z] == needle[z] && haystack[i + z] && i + z < len)
			z++;
		if (!needle[z])
		{
			result = (char *)(haystack + i);
			return (result);
		}
		i++;
	}
	return (NULL);
}

/*
int main () {
    char *s1 = "Hola como estas?";
    char *s2 = "como";
    
    printf("result: %s", ft_strnstr(s1, s2, 20));
    return 0;
}*/