#include <iostream>
#include <vector>

using namespace std;

void func (vector<int> &a)
{
    int n = a.size();
    int i,j;
    vector<int> b;
    int cnt=0;

    for (i=1; i<(1<<n); i++)
    {
        cnt = 0;
        for (j=0; j<n; j++)
        {
            if (i & (1<<j))
            {
                cnt++;
                b.push_back(a[j]);
            }
        }

        if (cnt == 2)
        {
            cout<<"[";
            for(j=0; j<b.size(); j++)
            {
                cout<<b[j]<<",";
            }
            cout<<"\b]\n";
        }

        b.clear();
    }
}
           
int main()
{

    vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);
    //set.push_back(4);

    func(set);

    return 0;
}
