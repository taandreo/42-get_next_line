#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int    main(void)
{
   char    *line;
   char    *file_name;
   int		fd;
   int      n;
   file_name = "/Users/tairan/42/get_next_line/tripouille/files/41_no_nl";
   // file_name = "/project/tripouille/files/41_no_nl";
   n = 0;
   fd = open(file_name, O_RDONLY);
   printf("%i\n", fd);
   line = get_next_line(fd);
   while (line)
   {
        printf("n: %i, s: %s", n, line);
        free(line);
        n++;
        line = get_next_line(fd);
   }
   close(fd);
   // get_next_line(1000);
}