/* Queues2Stack.C */
#include <queue>
#include <iostream>

template<typename T> class QueStack {

public:
  
  QueStack() {}
  
  virtual ~QueStack() {}
  
  int empty() {
    return q1.empty() && q2.empty();
  }
   
  void push(const T& val) {
    if(empty()) 
      q1.push(val);
    else if(q2.empty()) {
      q2.push(val);
      T tmp;
      while(!q1.empty()) {
        tmp = q1.front();
        q2.push(tmp);
        q1.pop();
      }
    } else {
      q1.push(val);
      T tmp;
      while(!q2.empty()) {
        tmp = q2.front();
        q1.push(tmp);
        q2.pop();
      }
    }
  }
  
  void pop() {
    if(empty()) 
      return;
    else if(q1.empty()) 
      q2.pop();
    else { 
      q1.pop();
      std::cout << "front" << q1.front() << std::endl;
      std::cout << "back" << q1.back() << std::endl;
    }
  }
  
  const T& top() {
    if(q1.empty()) 
      return q2.front();
    else 
      return q1.front();
  }
 
private:
  std::queue<int> q1;
  std::queue<int> q2;
};


int main()
{
  QueStack<int> stk;
  stk.push(1);  
  stk.push(2);  
  stk.push(3);  
  stk.pop();
  stk.push(4);  
  stk.pop();
  std::cout << stk.top() << std::endl;
}
