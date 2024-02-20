#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int fd = open("aa.txt", O_RDWR);
    if(fd < 0)
    {
        perror("open error");
        exit(1);
    }

    int stat = fcntl(fd, F_GETFL, 0);
    stat = stat | O_RDWR | O_APPEND;
    fcntl(fd, F_SETFL, stat);
    
    dup2(fd, 1);
    printf("HELLO WORLD, hhhhh\n");
    close(fd);

    return 0;
}
