#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main()
{
    int fd = open("./aa.txt", O_RDWR | O_CREAT, 0777);
    
    if(fd < 0){
        perror("Open error");
        exit(1);
    }

    close(fd);
    return 0;
}
