#include <stdio.h>
#include <stdint.h>


uint32_t func ()
{
   uint8_t arr[5] = {1,2,8,4,5};
   return arr[2];
}

int main()
{
 uint32_t x = func();

 printf("%u\n", x);

return 0;
}
