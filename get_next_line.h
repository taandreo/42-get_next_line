/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:23:06 by tairan            #+#    #+#             */
/*   Updated: 2022/07/02 01:52:39 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// utils
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
void	*ft_memcpy(void *dest, const void *src, size_t n);
// get_next_line
char	*get_next_line(int fd);
char	*join(char *line, char *text);
char	*get_text(char **buffer);
size_t	read_buffer(char **buffer, size_t size, int fd);

#endif
