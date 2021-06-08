#include <iostream>

using namespace std;

void func (string s, string g, int i)
{
    if (i >= s.length())
    {
        cout<<g;
        cout<<" ";
        return;
    }

    func (s, g, i+1);
    
    g.append(1, s[i]);

    func (s, g, i+1);
}

int main()
{
    string s = "abc";
    string g = "";

    func (s, g, 0);

    return 0;
}
