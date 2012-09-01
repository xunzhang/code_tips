/* Stacks2Queue.C */
#include <stack>
#include <iostream>

template <typename T> class StkQueue {

public:
  
  StkQueue() {}
  
  virtual ~StkQueue() {}
  
  int empty() {
    if(stk1.empty && stk2.empty())
      return 1;
    else
      return 0;
  }
   
  void enqueue(const T& val) {
    stk1.push(val); 
    tail = val;
  }

  void dequeue() {
    if(!stk2.empty())
      stk2.pop();
    else {
      T tmp;
      while(!stk1.empty()) {
        tmp = stk1.top();
        stk1.pop();
        stk2.push(tmp);
      }
      stk2.pop();
    }
  }
  
  const T& front() {
    if(stk2.empty()) {
      T tmp;
      while(!stk1.empty()) {
        tmp = stk1.top();
        stk1.pop();
        stk2.push(tmp);
      }
    }
    return stk2.top();
  } 

  const T& back() {
    return tail;
  }

private:
  std::stack<T> stk1;
  std::stack<T> stk2;
  T tail;
};

int main()
{
  StkQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.dequeue();
  queue.enqueue(4);
  queue.dequeue();
  queue.dequeue();
  queue.enqueue(5);
  std::cout << queue.front() << " and " << queue.back() << std::endl;
}
