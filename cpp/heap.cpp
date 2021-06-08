#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    priority_queue <int, vector<int>, greater<int> > x;
    stack<int> y;
    int i;

    for (i=0; i<5; i++)
    {
        y.push(i);
        x.push(i);
    }

    while (!y.empty())
    {
        cout<<y.top()<<"\n";
        y.pop();
    }

    cout <<"Heap="<<x.top();

    return 0;
}

