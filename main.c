#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int    main(void)
{
   char    *line;
   char    *file_name;
   int		fd;
   int      n;
   // file_name = "/Users/tairan/42/get_next_line/tripouille/files/alternate_line_nl_with_nl";
   file_name = "/project/tripouille/files/alternate_line_nl_with_nl";
   n = 0;
   fd = open(file_name, O_RDONLY);
   printf("%i\n", fd);
   line = get_next_line(fd);
   while (line)
   {
        printf("n: %i, s: %s", n, line);
        n++;
        line = get_next_line(fd);
   }
   close(fd);
}