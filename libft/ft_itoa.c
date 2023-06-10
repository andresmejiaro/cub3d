/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:34:02 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_array_mp(char *a, int number, int length)
{
	int		i;

	i = 0;
	if (length == 0)
	{
		a[0] = number + '0';
		return (a);
	}
	else if (number == -2147483648)
	{
		a[0] = '-';
		a[1] = '2';
		number = 147483648;
	}
	if (length < 1)
	{
		a[0] = 48;
		return (a);
	}
	while (number > 0)
	{
		a[length--] = (number % 10) + '0';
		number /= 10;
	}
	return (a);
}

int	ft_get_length_mp(int c)
{
	int	count;

	count = 0;
	if (c == -2147483648)
	{
		count = 11;
		return (count);
	}
	if (c == 0)
		count++;
	if (c < 0)
	{
		c *= -1;
		count++;
	}
	while (c > 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int c)
{
	char	*a;
	size_t	length;
	int		copy;

	copy = c;
	length = ft_get_length_mp(c);
	a = malloc(length + 1);
	if (!a)
		return (NULL);
	if (copy < 0)
	{
		a[0] = '-';
		copy = copy * -1;
	}
	ft_to_array_mp(a, copy, length - 1);
	a[length] = '\0';
	return (a);
}
