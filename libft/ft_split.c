/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:24:28 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nmbr_of_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count += 1;
		}
		else
			i++;
	}
	return (count);
}

char	*allocate_word(char *s, char c, int *start)
{
	int		length;
	char	*result;
	int		i;

	length = 0;
	while (s[*start] == c)
		(*start)++;
	while (s[*start + length] != c && s[*start + length])
		length++;
	if (length <= 0)
		return (NULL);
	result = (char *)ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = s[*start + i];
		i++;
	}
	*start += length + 1;
	return (result);
}

char	**ft_words_length_allocate(char *s, char c, int size)
{
	int		i;
	int		start;
	char	**result;

	i = 0;
	start = 0;
	result = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!s || !result)
		return (NULL);
	while (i < size)
	{
		result[i] = allocate_word(s, c, &start);
		if (!result[i])
		{
			while (i >= 0)
			{
				free(result[i]);
				i--;
			}
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}

void	chars_into_result(char *s, char c, char **array)
{
	int	i;
	int	x;
	int	j;

	x = 0;
	j = 0;
	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[x][j] = s[i];
			j++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				array[x][j] = '\0';
				x++;
				j = 0;
			}
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nmbr_words;

	if (!s)
		return (NULL);
	nmbr_words = nmbr_of_words(s, c);
	if (!nmbr_words)
	{
		result = (char **)malloc(sizeof(char *));
		if (!result)
			free(result);
		else
			result[0] = NULL;
		return (result);
	}
	result = ft_words_length_allocate((char *)s, c, nmbr_words);
	if (!result)
		return (NULL);
	chars_into_result((char *)s, c, result);
	return (result);
}
