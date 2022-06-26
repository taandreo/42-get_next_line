// #include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void test_read(int fd)
{
    int size = 10;
    int rt;
    static char buffer[11];
    rt = read(fd, buffer, size);
    buffer[10] = '\0';
    printf("return: %i buffer: %s\n", rt, buffer);
}

int main(void)
{
    // char *file_name = "ignore/frutas.txt";
    // int fd;
    // fd = open(file_name, O_RDONLY);
    // test_read(fd);
    // test_read(fd);
    // close(fd);
    static int tst;
    printf("%d\n", tst);
}