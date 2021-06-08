#include <iostream>

using namespace std;
class base
{
    int a;
    public:
    void set(int x)
    {
        a = x;
    }

    void get()
    {
        cout<<"a = "<<a<<"\n";
    }
};

class shared_ptr
{
    base *ptr;
    int *ref_cnt;

    public:
    shared_ptr (base *p)
    {
        ptr = p;
        ref_cnt = new int;
        *ref_cnt = 1;
        cout<<"Parametrized constructor: reference count = "<<*ref_cnt<<"\n";
    }

    shared_ptr()
    {
        ptr = 0;
        ref_cnt = 0;
        //cout<<"default constructor: reference count = "<<*ref_cnt<<"\n";
    }

    shared_ptr & operator= (const shared_ptr &x)
    {
        ptr = x.ptr;
        ref_cnt = x.ref_cnt;
        (*ref_cnt)++;
        cout<<"Overloaded assigment operator: reference count = "<<*ref_cnt<<"\n";
    }

    ~shared_ptr()
    {
        if (*ref_cnt > 1)
        {
            cout<<"destructor: reference count = "<<*ref_cnt<<"\n";
            (*ref_cnt)--;
            ref_cnt = 0;
            ptr = 0;
        }
        else if (*ref_cnt == 1)
        {
            cout<<"destructor: reference count = "<<*ref_cnt<<"\n";
            delete ref_cnt;
            ref_cnt = 0;
            delete ptr;
            ptr = 0;
        }
    }

    bool operator!()
    {
        return !ptr;
    }

    base * operator->()
    {
        if(ptr)
        {        
            return ptr;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    shared_ptr a;
    {
     shared_ptr b(new base);
     a = b;
    }
   
    a->set(4);
    a->get();


    return 0;
}
