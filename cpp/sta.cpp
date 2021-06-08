#include <iostream>

using namespace std;

class base
{
  int a;

  public:
  
  void getset(int x)
  {
    a = x;
    cout<<a<<endl;
  }

  static void point()
  {
    cout<<"Static function\n";
  }
};

int main()
{
  base obj;
 
  obj.getset(15);

  //base :: point();
  obj.point();

  return 0;
}
