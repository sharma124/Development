#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <errno.h>

int main()
{
 int fd[100000], i;
 struct sockaddr_in server;

 for (i=0; i<10000; i++)
 {
 
 fd[i] = socket(AF_INET, SOCK_DGRAM, 0);
 //int sd = socket(AF_INET, SOCK_DGRAM, 0);


 server.sin_family = AF_INET;
 //server.sin_port = htons(55000);
 server.sin_port = 0;
 inet_pton(AF_INET, "10.133.85.212", &server.sin_addr);

 if (bind (fd[i], (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0)
 {
  printf("Error [%d] [errorNo: %d] [%s]\n", fd[i], errno, strerror(errno));
 }
 else
 {
  printf("No error [%d]\n", fd[i]);
 }
 
 //sleep(1);
}
 /*close (fd);
 if (bind (sd, (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0)
 {
  printf("Error\n");
 }
 else
 {
  printf("No error\n");
 }*/

 for(;;);

return 0;
}
