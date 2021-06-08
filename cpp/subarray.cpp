#include <iostream>

using namespace std;

int main()
{
    string a = "abc";
    int i, j, k, n;
    n = a.length();
 
    for (i=0; i<n; i++)
    {
        for (j=i; j<n; j++)
        {
            for (k=i; k<=j; k++)
            {
                cout<<a[k];
            }

            cout<<", ";
        }
    }

    cout<<"\b\b \n";

    return 0;
}
