/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:19:05 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_size;
	int		s2_size;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)malloc(s1_size + s2_size + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, (s1_size + 1));
	ft_strlcat(result, s2, (s1_size + s2_size + 1));
	return (result);
}

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;

	s1 = "Hello";
	s2 = "World";
	result = ft_strjoin(s1, s2);
	printf("result: %s", result);
	return (0);
}*/