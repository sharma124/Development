#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int fd, len;
    int n;
    char buff[100];
    struct sockaddr_in server, client;

    fd = socket (AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(50600);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(fd, (struct sockaddr *)&server, sizeof(server));

    while (1) {


        n = recvfrom(fd, buff, 99, MSG_WAITALL, (struct sockaddr *)&client, &len);

        buff[n] = '\0';

        printf("Msg: %s", buff);

        sendto(fd, buff, n, MSG_CONFIRM, (const struct sockaddr *)&client, len);

    }

    return 0;
}
