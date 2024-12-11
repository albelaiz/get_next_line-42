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
		if (bytes == -1)
			return (free(buffer), buffer = NULL, NULL);
		buffer[bytes] = '\0';
		if (!copy)
			copy = ft_strdup("");
		tmp = copy;
		copy = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!copy)
			free(buffer);
			break;
	}
	free(buffer);
	return (copy);
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
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strncpy(line, str, i);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(copy);
		return (NULL);
	}
	copy = read_and_append(fd, copy);
	if (!copy)
		return (NULL);
	line = ft_extract_line(copy);
	copy = ft_after_line(copy);
	return (line);
}
