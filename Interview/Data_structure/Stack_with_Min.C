/* Stack_with_Min.C */
#include <stack>
#include <iostream>

template <typename T> class Adv_Stack {
public:
  
  Adv_Stack() { minv = 0;}
  
  virtual ~Adv_Stack() {}
  
  void push(const T& val) {
    if(stk1.empty()) {
      minv = val;
      stk2.push(val);
    }
    if(val < minv) {
      stk2.push(val);
      minv = val;
    }
    stk1.push(val);
  }
  
  void pop() {
    if(stk1.top() == minv)
      stk2.pop();
    stk1.pop();
  }
  
  const T& top() {
    return stk1.top();
  }
  
  const T& min() const {
    return stk2.top();  
  }

private:
  std::stack<T> stk1;
  std::stack<T> stk2;
  T minv;
};

int main()
{
  Adv_Stack<int> stk;
  stk.push(2);
  stk.push(3);
  stk.push(5);
  stk.push(1);
  stk.push(4);
  stk.pop();
  stk.pop();
  std::cout << stk.top() << std::endl;
  std::cout << stk.min() << std::endl;
}
