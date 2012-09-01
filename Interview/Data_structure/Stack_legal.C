/* Stack_legal.C */
#include <stack>
#include <iostream>

int legal_pop(const int *a){
  int low_indx = 1;
  int count = 0;
  std::stack<int> stk;
  for(int i = 0; i < sizeof(a); ++i) {
    if(a[i] >= low_indx) {
      for(int j = low_indx; j <= a[i]; ++j)
        stk.push(j);
      stk.pop();
      low_indx = a[i] - low_indx + 1;
    } else {
      if(stk.top() != a[i])
        return 0;
      stk.pop();
    }
  }
  return 1;
}

int main()
{
  const int a[5] = {4, 5, 3, 2, 1}; // 1  
  const int b[5] = {4, 5, 3, 1, 2}; // 0
  const int c[5] = {5, 4, 3, 2, 1}; // 1
  const int d[5] = {4, 3, 5, 1, 2}; // 0
  const int e[5] = {1, 2, 3, 4, 5}; // 1
  std::cout << legal_pop(a) << std::endl;
  std::cout << legal_pop(b) << std::endl;
  std::cout << legal_pop(c) << std::endl;
  std::cout << legal_pop(d) << std::endl;
  std::cout << legal_pop(e) << std::endl;
}
