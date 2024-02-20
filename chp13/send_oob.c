#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define BUF_SIZE 30

int main(int argc, char * argv[])
{
    int sock;
    struct sockaddr_in recv_adr;
    if(argc != 3)
    {
        printf("Usage : %s IP PORT \n", argv[0]);
        exit(1);
    }
    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&recv_adr, 0, sizeof(recv_adr));
    recv_adr.sin_family = AF_INET;
    recv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    recv_adr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr*)&recv_adr, sizeof(recv_adr));

    write(sock, "123", strlen("123"));
    send(sock, "4", strlen("4"), MSG_OOB);
    write(sock, "567", 3);
    send(sock, "890", 3, MSG_OOB);
    close(sock);
    return 0;
}


