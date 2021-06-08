#include <iostream>
#include <event2/listener.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main()
{
  //Variable declaration
  struct timeval time;
  int fd, flags = 0, ret, i, conn_fd;
  int count = 2, msgsz = 0;
  fd_set fds;
  struct sockaddr_in server;
  unsigned int opt = 1;
  char buff[10] = {0};

  //Socket creation
  fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
  
  //Setting to socket to resuse address.  
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (void *)&opt, sizeof(opt));
  
  //Setting listen socket non-blocking
  flags = fcntl (fd, F_GETFL, 0);
  fcntl (fd, F_SETFL, flags | O_NONBLOCK);


  server.sin_family = AF_INET;
  server.sin_port = htons(5090);
  inet_pton(AF_INET, "10.133.36.30", &server.sin_addr.s_addr);

  bind(fd, (const struct sockaddr *)&server, sizeof(server));

  listen (fd, 5);

  //Setting timeout time to 30 seconds.
  time.tv_sec = 30;
  time.tv_usec = 0;

  cout <<"Listen fd: "<<fd<<endl;

  sleep (10);
  //A client initiates a new connection towards  "10.133.36.30:5090".
  conn_fd = accept (fd, NULL, NULL);

  //Add new connection fd to  fd set to monitor. New Fd inherits non-blocking nature from listener.
  //So conn_fd is non-blocking.
  FD_ZERO (&fds);
  FD_SET (conn_fd, &fds);

  cout <<"Connection fd: "<<conn_fd<<endl;

  //Sanjul: As per you select should immediately return as the fd it is monitoring, is non-blocking. But it is only returning if some data is coming or timeout happens.
  //It means with timeout both blocking & non-blocking sockets behaving equally.
  
  
  //Count is to read only 2-times from the connection 
  while (count)
  {
   ret = select (FD_SETSIZE, &fds, NULL, NULL, &time);
   
   cout <<"Select: "<<ret<<endl;

   for (i=0; i < FD_SETSIZE; i++)
    {
      if (FD_ISSET(i, &fds))
      {
          msgsz = read (i, buff, sizeof(buff));
          buff [msgsz] = '\0';
          cout <<"Read-data: "<<buff<<endl;
      }
    }

   count--;
  }
  
  cout<<"Hello\n";

  return 0;
}