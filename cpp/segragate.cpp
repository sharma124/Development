#include <iostream>

using namespace std;


void func(int arr[], int n);

int main()
{
    //int arr[] = {0,0,0,6,0,8,2,3,0,4,0,1};
    int arr[] = {0,0,0,0,0,8,0,0,0,0,4,0,1, 0,0,0};
    int n = sizeof(arr)/sizeof(int);

    func (arr, n);

    return 0;
}

void func(int arr[], int n)
{
    /*int i=0, j=0;

    while ((i<n) && (j<n))
    {
        if (arr[i] == 0  && arr[j] != 0)
        {
            if (j > i)
            {
                arr[i] = arr[j];
                arr[j] = 0;

                i++;
                j++;
            }
            else
            {
                j = i+1;
            }
        }

        if (arr[i] != 0)
            i++;

        if(arr[j] == 0)
            j++;
    }*/

    int i = n-1, j = n-1;

    while ((i>=0) && (j>=0))
    {
        if (arr[i] == 0 && arr[j] != 0)
        {
            if (j < i)
            {
                arr[i] = arr[j];
                arr[j] = 0;
                i--;
                j--;
            }
            else
            {
                j = i-1;
            }
        }

        if (arr[i] != 0)
            i--;

        if (arr[j] == 0)
            j--;
    }

    cout<<"{";

    for (i=0; i<n; i++)
    {
        cout<<arr[i]<<", ";
    }

    cout<<"\b\b}";
}
