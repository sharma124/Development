#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<long long> nextLargerElement(vector<long long> &arr, int n){

    stack<int> s;
    int i = 0;

    for (i=0; i<n; i++)
    {
        cout<<arr[i]<<"\n";

        if (s.empty())
        {
            cout<<"When stack is empty\n";
            s.push(i);
        }
        else
        {
            if (arr[i] < arr[s.top()])
            {
                cout<<"When stack top is greater than current elemnt\n";
                s.push(i);
            }
            else
            {
                cout<<"When stack top is less than current element\n";
                while(!s.empty() && (arr[i] > arr[s.top()]))
                {
                    cout<<s.top()<<"\n";
                    arr[s.top()] = arr[i];
                    s.pop();


                }

                 cout<<"pop done \n";
                s.push(i);
            }
        }
    }


    while (!s.empty())
    {
        arr[s.top()] = -1;
        s.pop();
    }

    return arr;
}


int main()
{
    vector <long long> vec;
    vec . push_back(6);
    vec . push_back(4);
    vec . push_back(3);
    vec . push_back(2);
    vec . push_back(1);
    vec . push_back(5);
    int i = 0;

    nextLargerElement(vec, 6);

    for (i=0; i<6; i++)
    {
        cout<<vec[i]<<",";
    }

    return 0;
}

