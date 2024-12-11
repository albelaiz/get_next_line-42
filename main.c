#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while(line){
    line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}