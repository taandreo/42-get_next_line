/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:46 by tairan            #+#    #+#             */
/*   Updated: 2022/07/04 19:54:41 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	read_buffer(char **buffer, size_t size, int fd)
{
	int		read_size;
	char	*b;

	*buffer = malloc((size + 1) * sizeof(char));
	if (!*buffer)
		return (0);
	read_size = read(fd, *buffer, size);
	if (read_size <= 0)
	{
		free(*buffer);
		buffer[0] = NULL;
		return (0);
	}
	b = *buffer;
	b[read_size] = '\0';
	return (read_size);
}

static char	*ft_strchr(const char *str, int ch)
{	
	unsigned char	c0;
	unsigned char	c1;
	int				i;

	i = 0;
	c0 = (unsigned char) ch;
	while (str[i])
	{
		c1 = (unsigned char) str[i];
		if (c1 == c0)
			return ((char *)&str[i]);
		i++;
	}
	c1 = (unsigned char) str[i];
	if (c1 == c0)
		return ((char *)&str[i]);
	return (0);
}

static char	*get_text(char **buffer)
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

static char	*join(char *line, char *text)
{
	char	*tmp;

	if (!line)
		return (text);
	tmp = ft_strjoin(line, text);
	free(line);
	free(text);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	size_t		read_size;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1023)
		return (NULL);
	line = NULL;
	read_size = 0;
	if (!buffer[fd])
		read_size = read_buffer(&buffer[fd], BUFFER_SIZE, fd);
	while (read_size || buffer[fd])
	{
		line = join(line, get_text(&buffer[fd]));
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
		if (!buffer[fd])
			read_size = read_buffer(&buffer[fd], BUFFER_SIZE, fd);
	}
	return (line);
}
