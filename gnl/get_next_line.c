/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:48:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 13:01:46 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_save(int fd, char *save)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (!ft_strchr(save, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read != 0)
		{
			if (bytes_read == -1)
			{
				free(save);
				save = NULL;
				return (free(buffer), NULL);
			}
			buffer[bytes_read] = '\0';
			save = ft_strjoin_free(save, buffer);
		}
	}
	return (free(buffer), save);
}

char	*ft_get_line(char *save)
{
	char	*result;
	int		i;

	i = 0;
	if (!save || !save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	result = (char *)malloc(i + 1);
	if (!result)
		return (free(result), NULL);
	ft_strlcpy(result, save, i + 1);
	return (result);
}

char	*ft_cut_line(char *save)
{
	char	*result;
	int		i;
	int		size_to_copy;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	size_to_copy = ft_strlen(save) - i;
	result = (char *)malloc(size_to_copy + 1);
	if (!result)
		return (free(save), NULL);
	ft_strlcpy(result, (save + i), size_to_copy + 1);
	free(save);
	return (result);
}

char	*get_next_line(int fd)
{
	char static	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(save), NULL);
	save = ft_read_save(fd, save);
	if (!save)
		return (free(save), NULL);
	line = ft_get_line(save);
	if (!line || line[0] == '\0')
	{
		free(save);
		save = NULL;
		return (free(line), NULL);
	}
	save = ft_cut_line(save);
	return (line);
}
