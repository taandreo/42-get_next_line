/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:23:31 by tairan            #+#    #+#             */
/*   Updated: 2022/07/01 00:35:32 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen((char *) src);
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_size;
	size_t	s2_size;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	dest = ft_calloc(s1_size + s2_size + 1, sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, s1_size);
	ft_memcpy(&dest[s1_size], s2, s2_size);
	dest[s1_size + s2_size] = '\0';
	return (dest);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (__SIZE_MAX__ / size < num)
		return (NULL);
	p = malloc(num * size);
	if (!p)
		return (NULL);
	while (i < num * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *) p);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
