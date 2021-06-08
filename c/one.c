#include <stdio.h>

static int i = 1;  
int sub();
int main()  
{  
sub();  
printf("sub: %d\n", i);
return 0;
}
 
int sub()  
{  
static int i = 2;  
printf("sub: %d\n", i);  
}
