#include <iostream>
#include <map>
using namespace std;
void func (int arr[], int x, int k);


int main()
{
  int a[]= {1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4};

  func(a, 16, 2);

  return 0;
}

void func (int arr[], int x, int k)
{

  /*map<int, int> mmap;
  map<int, int> :: iterator iter;
  int i, count=0;

  for (i=0; i<x; i++)
  {
     iter = mmap.find(arr[i]);

     if (iter != mmap.end())
     {
       if (iter->second < k+1)
       {
         iter ->second ++;
       }
     }
     else
     {
       mmap[arr[i]] = 1;
     }
  }

  iter = mmap.begin();
  int write = 0;
  for (; iter != mmap.end(); iter++)
  {
    count = iter->second;
    cout <<count<<"\n";
    while(count)
    {
      arr[write++] = iter->first;
      count--;
    }
  }*/

  int i, write;
  int n, j, count;

  n =arr[0];
  write = 1;
  count=k;

  for (i=1; i<x; i++)
  {
    /*if (arr[i] == n)
    {
      for (j=0; j<k; j++)
      {    
        if (arr[i+j] !=n)
        {
          break;
        }

        arr[write++] =  arr[i+j];
      }

      for (; (arr[i+j] == n); j++);

      i = i+j-1;
      continue;
    }*/
    if (arr[i] == n)
    {
      if (count)
      {
        arr[write++] = arr[i];
        count--;
      }
    }
    else
    {
      arr[write++] = arr[i];
      n = arr[i];
      count = k;
    }
  }

  for (i=0; i<write; i++)
  {
    cout <<arr[i]<<" ";
  }

  cout<<"\n";

}
