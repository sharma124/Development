#include <iostream>

using namespace std;

int count(int a)
{
    unsigned int c=0, i;
    cout<<(sizeof(int)*8)<<"\n";

    for (i=0; i<sizeof(int)*8; i++)
    {
        if (a & (1 << i))
        {
            c++;
        }
    }

    return c;
}

int count1(int a)
{
    unsigned int c=0, i;
    for (i=0; i<sizeof(int)*8; i++)
    {
        if (a & 1)
            c++;

        a = a >> 1;
    }

    return c;
}

int main()
{
    int n = -15;
    int x = 10;

  cout<<count(n)<<" "<<count1(n)<<"\n";

  return 0;
}
