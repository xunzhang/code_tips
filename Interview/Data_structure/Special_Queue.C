/* Special_Queue.C */
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T> class SepQueue {

public:

  SepQueue() : ind1(0), ind2(0) {}

  ~SepQueue() {}

  void enqueue(T t) {
    ind1 ++;
    q.push(t);
    vec.push_back(t);
    // check out min and max
    if(min_q.size() == 0)
      min_q.push(t);
    else if(t <= min_q.front())
      min_q.push(t);

    if(max_q.size() == 0)
      max_q.push(t);
    else if(t >= max_q.front())
      max_q.push(t);
  }
   
  T dequeue() {
    if(q.size() == 0) return -1;
    ind1 ++;
    T tmp = q.front();
    q.pop();
    vec.pop_back();
    // check out min and max
    if(tmp == min_stk.top())
      min_stk.pop();
    if(tmp == max_stk.top())
      max_stk.pop(); 
    std::cout << tmp << std::endl;
    std::cout << std::endl;
    return tmp;
  }
  
  size_t patition(std::vector<T>& vec, size_t beg, size_t end) {
    size_t i = beg - 1, j;
    T tmp;
    T pivot = vec[end];
    for(j = beg; j < end; ++j) {
      if(vec[j] < pivot) { i++; tmp = vec[i]; vec[i] = vec[j]; vec[j] = tmp; }
      tmp = vec[i + 1]; vec[i + 1] = vec[end]; vec[end] = tmp;
    }
    return i + 1;
  }
   
  T peekMedian() {
    if(q.size() == 0) return -1;
    T p_res;
    size_t beg = 0, end = vec.size() - 1;
    size_t mid = vec.size() % 2 != 0 ? end / 2 : end / 2 + 1;
    if(ind2 == ind1) {
      return inter_val;
    } else {
      for(p_res = patition(vec, beg, end); p_res != mid; p_res = patition(vec, beg, end)) {
        if(p_res > mid) {
          end = p_res - 1;  
        } else {
          beg = p_res + 1;
          mid = mid - beg; 
        }
      }
      inter_val = vec[mid];
      ind2 = ind1; 
      return inter_val;
    }
  }
  
  T peekMaximum() { return max_stk.top(); }
  
  T peekMinimum() { return min_stk.top(); } 

private:
  size_t ind1;
  size_t ind2;
  T inter_val;
  std::queue<T> q;
  std::vector<T> vec;
  std::queue<T> min_q;
  std::queue<T> max_q;
}; // end of class SepQueue

int main()
{
  SepQueue<int> obj;
  obj.enqueue(1);  
  obj.dequeue();
  obj.enqueue(3);  
  obj.enqueue(4);
  obj.enqueue(2);
  std::cout << obj.peekMaximum() << std::endl;  
  std::cout << obj.peekMinimum() << std::endl;  
}


