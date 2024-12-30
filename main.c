#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    int fd =  open("eray.txt", O_RDONLY);
    if (fd < 0)
        return -1;
    while((str = get_next_line(fd)) != NULL)
    {
        printf("%s",str);
        free(str);
    }
}
