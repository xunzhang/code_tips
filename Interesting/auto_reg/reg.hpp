#ifndef REG_HPP
#define REG_HPP
#include <vector>
#include "typedef.hpp"
#include "func.hpp"

namespace local {

class Reg {
public:
  Reg() {
    reg_list.push_back(local::f1);
    reg_list.push_back(local::f2);
    cnt = 2;
  };
  int add_func(local::pfunc pf) {
    cnt ++;
    reg_list.push_back(pf);
    return cnt - 1;
  }
  void run(int i, int j) {
    reg_list[i](j);
  }
   
private:
  std::vector<local::pfunc> reg_list;
  int cnt;
};
}

#endif
