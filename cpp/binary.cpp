#include <iostream>

using namespace std;

void func(int n, string &s)
{
    if (n==1)
    {
        s+='1';
        return;
    }

    func(n/2, s);

    if (n & 1)
    {
        s+='1';
    }
    else
    {
        s+='0';
    }
}

int main()
{
    int a = 2;
    string b;

    func(a, b);

    cout<<b<<"\n";

    return 0;
}
