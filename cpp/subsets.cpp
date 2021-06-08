#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
void func(vector<int> &a, int i, int m, vector<int> b)
{
    if (b.size() == m)
    {
        cnt++;
        cout<<cnt;
        cout<<"[";
        for (int j=0; j<m; j++)
        {
            cout<<b[j]<<",";
        }

        cout<<"\b]\n";
        return;
    }

    if ((a.size() + b.size() -i) < m)
    {
        return;
    }

    /*if (i >= a.size())
    {
        return;
    }*/

    func(a, i+1, m, b);

    b.push_back(a[i]);

    func(a, i+1, m, b);
}

int main()
{
    vector<int> set, subset;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);
    set.push_back(4);
    set.push_back(2);
    set.push_back(9);
    set.push_back(1);
    set.push_back(6);
    set.push_back(3);
    set.push_back(2);

    func(set, 0, 4, subset);

    return 0;
}
