#include <iostream>

using namespace std;

class base
{
    int x;
public:
    virtual void print()
    {
        cout<<"x: "<<x<<"\n";
    }
};

class derived : public base
{
    int y;
public:
    void print()
    {
        cout<<"y: "<<y<<"\n";
    }
};

class comp
{
    base b;
    int z;
public:
    void print()
    {
        cout<<"z: "<<z<<"\n";
    }
};

int main()
{
    base *ptr = new derived;
    ptr->print();
    ptr = (base *)new comp;
    ptr->print();

    return 0;
}



