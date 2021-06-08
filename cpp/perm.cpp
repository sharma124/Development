#include <iostream>
#include <cstring>

using namespace std;

void func(char *ptr, int i, int n)
{
    if (i == n-1)
    {
        cout<<ptr<<"\n";
        return;
    }

    char temp;

    for (int j=i; j<n; j++)
    {
        temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;

        func(ptr, i+1, n);

        //backtrack
        temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }
}

int main()
{
    char p[] = "abc";

    func(p, 0, strlen(p));

    return 0;
}
