/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:46 by tairan            #+#    #+#             */
/*   Updated: 2022/06/30 22:13:31 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char    *get_next_line(int fd)
{
    static char *buffer[1024];
    size_t  read_size;
    char *line;

    if (BUFFER_SIZE == )
    line = NULL;
    read_size = 0;
    if (!buffer[fd])
        read_size = read_buffer(buffer, BUFFER_SIZE, fd);
    // buffer_verb = buffer[fd];
    // printf("%s", buffer_verb);
    while(read_size || buffer[fd]){
        line = join(line, get_text(&buffer[fd]));
        if (line[ft_strlen(line) - 1] == '\n')
            return (line);
        if (!buffer[fd])
            read_size = read_buffer(buffer, BUFFER_SIZE, fd);
    }
    return line;
}

size_t  read_buffer(char **buffer, size_t size, int fd)
{
    size_t read_size;
    
    buffer[fd] = malloc(size + 1 * sizeof(char));
    if (!buffer[fd])
        return (0);
    read_size = read(fd, buffer[fd], size);
    if (read_size ==  0)
    {
        free(buffer[fd]);
        buffer[fd] = NULL;
        return (0);
    }
    (buffer[fd])[read_size] = '\0';
    return (read_size);
}

char    *join(char *line, char *text)
{
    if (!line)
        return (text);
    return (ft_strjoin(line, text));
}

char    *get_text(char **buffer)
{
    char    *line;
    size_t  len;
    // size_t  line_size;
    size_t  n;
    char    *tmp;

    tmp = NULL;
    len = ft_strlen(*buffer);
    if(!ft_strchr(*buffer, '\n'))
        n = len;
    else
        n = (ft_strchr(*buffer, '\n') - *buffer) + 1;
    // printf("%zu\n", n);
    line = malloc((n + 1) * sizeof(char));
    if (!line)
        return NULL;
    ft_strlcpy(line, *buffer, n + 1);
    // printf("line: %s", line);
    if (n != len)
    {
        tmp = malloc((len - n + 1)  * sizeof(char));
        ft_strlcpy(tmp, &(*buffer)[n], len - n + 1);
    }
    // printf("tmp: %s", tmp);
    free(*buffer);
    buffer[0] = tmp;
    tmp = NULL;
    return(line);
}

// char    *get_text(char **buffer, int fd)
// {
//     char    *line;
//     size_t  len;
//     size_t  line_size;
//     char    *n_addr;
//     char    *tmp;
    
//     len = ft_strlen(*buffer);
//     n_addr = ft_strrchr(*buffer, '\n');
//     // if (!n_addr)
//         // n_addr = &buffer[fd][len - 1];
    
//     line_size = (((n_addr + 1) - buffer[fd]) + 1);
//     line = malloc(line_size * sizeof(char));
//     if (!line)
//         return NULL;
//     ft_strlcpy(line, buffer[fd], line_size);
//     if (n_addr == &buffer[fd][len - 1])
//     {
//         free(buffer[fd]);
//         buffer[fd] = NULL;
//         return (line);
//     }
//     line_size = (&buffer[fd][len - 1]  - n_addr) + 2;
//     tmp = malloc(line_size * sizeof(char));
//     ft_strlcpy(tmp, n_addr, line_size);
//     buffer[fd] = tmp;
//     free(tmp);
//     return(line);
// }

// abac\nate 8


int main(void)
{
    // char *str;
    // static char *buffer[10];

    // buffer[3] = malloc(21 * sizeof(char));
    // // ft_memcpy(buffer[3], "01234\n67\n90123456\n89", 20);
    // ft_memcpy(buffer[3], "01234567890123456789", 20);
    // buffer[3][20] = '\0';
    // // printf("%s\n", buffer[3]);
    // get_text(&buffer[3]);
    // printf("buffer: %s", buffer[3]);
    // printf("str: %sbuffer: %s\n", str, buffer[3]);
    // str = get_text(buffer, 3);
    // printf("str: %sbuffer: %s\n", str, buffer[3]);
    // str = get_text(buffer, 3);
    // printf("str: %sbuffer: %s\n", str, buffer[3]);
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
    // printf("%i: %s", n, line);
    while(line)
    {
        printf("n: %i, s: %s", n, line);
        n++;
        line = get_next_line(fd);
    }
    close(fd);
}

// char *get_next_line(int fd)
// {
//     static char     buffer[BUFFER_SIZE];
//     static size_t   index;
//     static size_t   read_size;
//     char            *text;
//     char            *line;
//     char            *tmp;

//     read_size = 1;
//     line = ft_calloc(1, 1);
//     while(read_size){
//         if (index == 0)
//         {
//             read_size = read(fd, buffer, BUFFER_SIZE);
//             if (read_size == 0)
//                 break ;
//         }
//         text = get_text(read_size, buffer, &index);
//         if (text == NULL)
//         {
//             if (line != NULL)
//                 free(line);
//             return NULL;
//         }
//         tmp = ft_strjoin(line, text);
//         free(text);
//         free(line);
//         line = tmp;
//         tmp = NULL;
//         if (index >= read_size)
//             index = 0;
//         if (line[ft_strlen(line) - 1] == '\n')
//             return (line);
//         if (index > read_size && read_size < BUFFER_SIZE)
//             return (line);
//     }
//     return NULL;
// }

// char get_Line()
//     ft_strlen()
// char *get_text(int size, char *buffer, size_t *index)
// {
//     char    *line;
//     int     line_size;
//     char    *n_addr;

//     n_addr = ft_memchr(&buffer[*index], '\n', size - (*index));
//     if (!n_addr)
//         n_addr = &buffer[size - 1];
//     line_size = (((n_addr + 1) - &buffer[*index]) + 1);
//     line = malloc(line_size * sizeof(char));
//     if (!line)
//         return NULL;
//     ft_strlcpy(line, &buffer[*index], line_size);
//     *index = n_addr + 1 - buffer;
//     return (line);
// }