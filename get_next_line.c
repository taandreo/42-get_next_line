/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:46 by tairan            #+#    #+#             */
/*   Updated: 2022/06/28 18:51:21 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char *get_next_line(int fd)
{
    static char     buffer[BUFFER_SIZE];
    static size_t   index;
    static size_t   read_size;
    char            *text;
    char            *line;
    char            *tmp;

    read_size = 1;
    line = ft_calloc(1, 1);
    while(read_size){
        if (index == 0)
        {
            read_size = read(fd, buffer, BUFFER_SIZE);
            if (read_size == 0)
                break ;
        }
        text = get_text(read_size, buffer, &index);
        if (text == NULL)
        {
            if (line != NULL)
                free(line);
            return NULL;
        }
        tmp = ft_strjoin(line, text);
        free(text);
        free(line);
        line = tmp;
        tmp = NULL;
        if (index >= read_size)
            index = 0;
        if (line[ft_strlen(line) - 1] == '\n')
            return (line);
        if (index > read_size && read_size < BUFFER_SIZE)
            return (line);
    }
    return NULL;
}

char *get_text(int size, char *buffer, size_t *index)
{
    char    *line;
    int     line_size;
    char    *n_addr;

    n_addr = ft_memchr(&buffer[*index], '\n', size - (*index));
    if (!n_addr)
        n_addr = &buffer[size - 1];
    line_size = (((n_addr + 1) - &buffer[*index]) + 1);
    line = malloc(line_size * sizeof(char));
    if (!line)
        return NULL;
    ft_strlcpy(line, &buffer[*index], line_size);
    *index = n_addr + 1 - buffer;
    return (line);
}

int main(void)
{
    // char *str;
    // static size_t index;
    // static char buffer[20];
    // printf("%zu\n", index);
    // ft_memcpy(buffer, "01234\n67\n90123456\n89", 20);
    // str = get_text(20, buffer, &index);
    // printf("str: %sfind: %zu\n", str, index);
    // str = get_text(20, buffer, &index);
    // printf("str: %sfind: %zu\n", str, index);
    // str = get_text(20, buffer, &index);
    // printf("str: %sfind: %zu\n", str, index);
    // str = get_text(20, buffer, &index);
    // printf("str: %sfind: %zu\n", str, index);
    // str = get_text(20, buffer, &index);
    // printf("str: %sfind: %zu\n", str, index);
    // free(str);
    char    *line;
    char *file_name = "ignore/frutas.txt";
    int fd;
    int n;

    n = 0;
    fd = open(file_name, O_RDONLY);
    
    line = get_next_line(fd);
    while(line)
    {
        printf("n: %i, s: %s", n, line);
        n++;
        line = get_next_line(fd);
    }
    close(fd);
}