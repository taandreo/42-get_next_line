/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:23:31 by tairan            #+#    #+#             */
/*   Updated: 2022/06/25 19:21:57 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*rp;

	i = 0;
	rp = (unsigned char *)s;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return (rp + i);
		i++;
	}
	return (NULL);
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
