#include <iostream>
#include "reg.hpp"

void f3(double a) {
  std::cout << "i am in f3." << std::endl;
  std::cout << a + 3 << std::endl;
}

int main()
{
  int indx;
  local::Reg obj;
  indx = obj.add_func(f3); 
  obj.run(indx, 0);
}
