/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:11 by albelaiz          #+#    #+#             */
/*   Updated: 2024/12/16 15:51:53 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_append(int fd, char *copy)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		if (!copy)
			copy = ft_strdup("");
		tmp = copy;
		copy = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!copy)
			break ;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), copy);
}

char	*ft_extract_line(char *str)
{
	int		i;
	char	*line;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_after_line(char *copy)
{
	int		i;
	char	*remaining;

	i = 0;
	while (copy[i] && copy[i] != '\n')
		i++;
	if (!copy[i])
	{
		free(copy);
		return (NULL);
	}
	remaining = ft_strdup(copy + i + 1);
	free(copy);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*copy;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(copy), copy = NULL, NULL);
	copy = read_and_append(fd, copy);
	if (!copy)
		return (NULL);
	line = ft_extract_line(copy);
	copy = ft_after_line(copy);
	return (line);
}
