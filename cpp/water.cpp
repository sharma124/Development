#include <iostream>
using namespace std;

void func(int arr[], int n);

int main() {

    int T, i;
    int arr[10], n;

    cin>>T;

    while (T--)
    {
        cin>>n;

        for (i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        func(arr, n);
    }

    return 0;
}

void func(int arr[], int n)
{
    if (n==1)
    {
        if (arr[0] < 0)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }

    cout<<"NO\n";
}
