/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:08:05 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocating_memmory(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (len > ft_strlen(s) && s[0] != '\0' && start < ft_strlen(s))
		result = (char *)malloc(ft_strlen(s) - start + 1);
	else if (s[0] != '\0' && start < ft_strlen(s) && len > ft_strlen(s) - start)
		result = (char *)malloc(ft_strlen(s) - start + 1);
	else if (start < ft_strlen(s) && len <= ft_strlen(s) && s[0])
		result = (char *)malloc((len + 1));
	else
		result = (char *)malloc((1));
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	sub = allocating_memmory(s, start, len);
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && len > 0)
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}
