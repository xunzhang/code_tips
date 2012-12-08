#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>

namespace local{

extern void f1(double);
extern void f2(double);

void f1(double a) {
  std::cout << "i am in f1." << std::endl;
  std::cout << a + 1 << std::endl;
}

void f2(double a) {
  std::cout << "i am in f2." << std::endl;
  std::cout << a + 2 << std::endl;
}
}

#endif
