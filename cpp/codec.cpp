#include <iostream>
using namespace std;

void func (int arr[], int n);

int main() {

  int T, n;
  int arr[5], i;

  cin>>T;
  while (T-- > 0)
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

void func (int arr[], int n)
{
  int i, j, max = 0, min = 6;
  int cnt = 0;

  for (i=0; i<n; i++)
  {
    cnt = 1;

    for (j=i+1; j<n; j++)
    {
      if (arr[i] > arr[j])
      {
        cnt++;
      }
    }

    if (cnt > max)
    {
      max = cnt;
    }

    if (cnt < min)
    {
      min = cnt;
    }
  }

  cout <<min<<" "<<max<<"\n";
}
