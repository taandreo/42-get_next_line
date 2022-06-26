/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:46 by tairan            #+#    #+#             */
/*   Updated: 2022/06/25 22:46:07 by tairan           ###   ########.fr       */
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
    line = NULL;
    while(read_size){
        if (index == 0 || index >= BUFFER_SIZE)
        {
            read_size = read(fd, buffer, BUFFER_SIZE);
            if (read_size == 0)
                return NULL;
        }
        text = get_text(read_size, buffer, &index);
        if (text == NULL)
        {
            if (line != NULL)
                free(line);
            return NULL;
        }
        tmp = ft_strjoin(line, text);
        line = tmp;
        free(tmp);
        tmp = NULL;
        free(text);
        if (line[ft_strlen(text) - 1] == '\n')
            return (line);
        if (index > read_size && read_size < BUFFER_SIZE)
            return (line); 
    }
    return (NULL);
}

char *get_text(int size, char *buffer, size_t *index)
{
    char    *line;
    int     line_size;
    char    *n_addr;

    n_addr = ft_memchr(&buffer[*index], '\n', size);
    if (!n_addr)
        n_addr = &buffer[size];
    line_size = (((n_addr + 1) - &buffer[*index]) + 1);
    line = malloc(line_size * sizeof(char));
    if (!line)
        return NULL;
    ft_strlcpy(line, &buffer[*index], line_size);
    // printf("index inside 1: %i\n", *index);
    // printf("buffer: %p, n_addr: %p\n", buffer, n_addr);
    *index = n_addr + 1 - buffer;
    // printf("index inside 2: %i\n", *index);
    return (line);
}

int main(void)
{
    // char *str;
    // static int index;
    // static char buffer[10];
    // printf("%i\n", index);
    // ft_memcpy(buffer, "01234\n67\n9", 10);
    // str = get_line(10, buffer, &index);
    // printf("str: %sfind: %i\n", str, index);
    // str = get_line(10, buffer, &index);
    // printf("str: %sfind: %i\n", str, index);
    // str = get_line(10, buffer, &index);
    // printf("str: %sfind: %i\n", str, index);
    // free(str);
    char    *line;
    char *file_name = "ignore/frutas.txt";
    int fd;
    fd = open(file_name, O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    close(fd);
}