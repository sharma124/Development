#include <stdio.h>

int main()
{
    const int a = 7;
    int *p = &a;
    *p = 4;
    int *b = 0;
    int c = *b;

    printf("%ld\n", ((char *)(p+1) - (char *)p));

    return 0;
}
