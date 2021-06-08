#include <iostream>
//#include <unordered_map>
#include <map>
using namespace std;

int func(int f[], int n, int k);

int main() {

  int T, family[1000];
  int n, k, i;

  cin>>T;

  while (T-- > 0)
  {
    cin>>n; cin>>k;
    for (i=0; i<n; i++)
    {
      cin>>family[i];
    }

    cout <<"Ans: "<<func (family, n, k);
    cout<<"\n";
  }

  return 0;
}

int func(int f[], int n, int k)
{
  int dp[1000];
  map<int, int> table;
  map<int, int> :: iterator it;
  int i, j, min, cost, currcost;

  dp[0] = k;

  for (i=1; i<n; i++)
  {
    j = i;
    table.clear();
    table[f[j]] = 1;
    cost = k;
    min = cost + dp[j-1];

    for (j = j-1; j>=0; j--)
    {
      it = table.find(f[j]);

      if (it != table.end())
      {
        if (it->second == 1)
          cost = cost + 2;
        else
          cost  = cost + 1;

        it -> second ++;
      }
      else
      {
        table[f[j]] = 1;
      }

      currcost = cost;

      if (j != 0)
      {
        currcost = cost + dp[j-1];
      }

      if (min > currcost)
      {
        min = currcost;
      }
    }

    dp[i] = min;
    cout<<"dp["<<i<<"] = "<<dp[i]<<"\n";
  }

  return dp[n-1];
}
