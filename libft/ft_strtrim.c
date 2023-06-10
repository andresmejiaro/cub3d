/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:48:08 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*to_empty_pointer_mp(char *str)
{
	str = (char *)malloc(1);
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		index_length_s1;
	int		j;
	char	*result;

	if (!s1)
		return (NULL);
	result = 0;
	if ((s1 != NULL && s1[0] == '\0'))
		return (to_empty_pointer_mp(result));
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	index_length_s1 = ft_strlen(s1);
	while (ft_strchr(set, s1[index_length_s1 - 1]) && s1[index_length_s1 - 1])
		index_length_s1--;
	j = index_length_s1 - i;
	if (j <= 0)
		return (to_empty_pointer_mp(result));
	result = (char *)malloc(j + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, (s1 + i), j);
	result[j] = 0;
	return (result);
}
