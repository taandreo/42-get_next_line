/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:46 by tairan            #+#    #+#             */
/*   Updated: 2022/07/01 00:34:47 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	size_t		read_size;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = NULL;
	read_size = 0;
	if (!buffer[fd])
		read_size = read_buffer(buffer, BUFFER_SIZE, fd);
	while (read_size || buffer[fd])
	{
		line = join(line, get_text(&buffer[fd]));
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
		if (!buffer[fd])
			read_size = read_buffer(buffer, BUFFER_SIZE, fd);
	}
	return (line);
}

size_t	read_buffer(char **buffer, size_t size, int fd)
{
	size_t	read_size;

	buffer[fd] = malloc(size + 1 * sizeof(char));
	if (!buffer[fd])
		return (0);
	read_size = read(fd, buffer[fd], size);
	if (read_size == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	(buffer[fd])[read_size] = '\0';
	return (read_size);
}

char	*get_text(char **buffer)
{
	char	*line;
	size_t	len;
	size_t	n;
	char	*tmp;

	tmp = NULL;
	len = ft_strlen(*buffer);
	if (!ft_strchr(*buffer, '\n'))
		n = len;
	else
		n = (ft_strchr(*buffer, '\n') - *buffer) + 1;
	line = malloc((n + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer, n + 1);
	if (n != len)
	{
		tmp = malloc((len - n + 1) * sizeof(char));
		ft_strlcpy(tmp, &(*buffer)[n], len - n + 1);
	}
	free(*buffer);
	buffer[0] = tmp;
	tmp = NULL;
	return (line);
}

char	*join(char *line, char *text)
{
	if (!line)
		return (text);
	return (ft_strjoin(line, text));
}

int	main(void)
{
	char	*line;
	char	*file_name;
	int		fd;
	int		n;

	file_name = "ignore/frutas.txt";
	n = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("n: %i, s: %s", n, line);
		n++;
		line = get_next_line(fd);
	}
	close(fd);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
