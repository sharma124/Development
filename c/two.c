#include <stdio.h>

int main()  
{

  
struct str{  
unsigned char a:1;  
unsigned char b:1;  
unsigned char c:1;  
unsigned char d:5;  
} x;  

union un{  
struct str n;  
char ch;  
}b;  

b.ch = 252; 
printf("%d %d %d %d \n",b.n.b, b.n.a, b.n.d, b.n.c);
printf("%d %d %d %d %x\n",b.n.b, b.n.a, b.n.d, b.n.c, b.ch);
/* x=(struct str)252; //11111100
printf("%d %d %d %d\n",x.b, x.a, x.d, x.c);*/
return 0;  
}  
