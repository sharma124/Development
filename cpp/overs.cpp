#include <iostream>
using namespace std;

void func(int n, int k, int l);

int main() {

  int T, l;
  int n, k;

  cin>>T;
  while (T--)
  {
    cin>>n>>k>>l;

    func(n, k, l);
  }
  return 0;
}

void func(int n, int k, int l)
{
  float overs = (float)n;
  int i, j=1;

  if ( overs/k > l)
  {
    cout<<"-1\n";
    return;
  }

  for (i=1; i<=n; i++)
  {
    if (j== (k+1))
      j =1;

    cout<<j++<<" ";
    //cout<<(i%(k+1))<<" ";
  }

  cout<<"\n";
}
