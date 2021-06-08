#include <iostream>
#include <map>
using namespace std;

int func(int a[], int n);

int main() {

  int T, i;
  int a[10000], n;
  
  cin>>T;
  while (T-- > 0)
  {
      cin>>n;
      for (i=0; i<n; i++)
      {
          cin>>a[i];
      }
      
      cout<<func(a, n);
      cout<<"\n";
  }
  return 0;
}

int func(int a[], int n)
{
    int i, map1[11] = {0,0,0,0,0,0,0,0,0,0,0};
    int max, key;
    map<int, int> map2;
    map<int, int> :: iterator iter;
    
    for (i=0; i<n; i++)
    {
        map1[a[i]]++;
    }
    
    for (i=1; i<11; i++)
    {
        if (map1[i] == 0)
          continue;
          
        iter = map2.find(map1[i]);
        
        if (iter == map2.end())
        {
            map2[map1[i]] = 1;
        }
        else
        {
            iter->second++;
        }
    }
    
    iter = map2.begin();
    max = iter->second;
    key = iter->first;
    
    iter++;
    for (; iter != map2.end(); iter++)
    {
        if ((iter->second) > max)
        {
            key = iter->first;
        }
    }
    
    return key;
}

