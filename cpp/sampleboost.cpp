#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;

int main()
{
  boost::shared_ptr<int> lpMyInt;

  if (!lpMyInt)
  {
    cout<<"Hello\n";
  }
  else
  {
    cout<<"Hi\n";
  }

  return 0;
}
