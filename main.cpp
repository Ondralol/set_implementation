#include "set.h"

/* Just a little showcase */
int main ()
{
  CSet<int> a;
  a.Insert(10);
  a.Insert(550);
  a.Insert(0);
  a.Insert(10);
  a.Insert(50);
  a.Insert(20);
  std::cout << a << std::endl;
  std::cout << a.Delete(0) << std::endl;
  std::cout << a << std::endl;
  a.Delete(20);
  std::cout << a << std::endl;
  return 0;
}

