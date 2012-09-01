/* Reverse_Stack.C */
#include <stack>
#include <iostream>

template<typename T> void Reverse_Stack(std::stack<T>& stk) {
  if(!stk.empty()) {
    T top = stk.top();
    stk.pop();
    Reverse_Stack(stk);
    Add_Bottom(stk, top);
  } 
}

template<typename T> void Add_Bottom(std::stack<T>& stk, T val) {
  if(stk.empty())
    stk.push(val);
  else {
    T t = stk.top();
    stk.pop();
    Add_Bottom(stk, val);
    stk.push(t);
  }
}

int main()
{
  std::stack<int> stk;
  stk.push(1);  
  stk.push(2);  
  stk.push(3);  
  Reverse_Stack(stk);
  std::cout << stk.top() << std::endl;
  stk.pop();
  std::cout << stk.top() << std::endl;
  stk.pop();
  std::cout << stk.top() << std::endl;
}
