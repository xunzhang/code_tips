/*
 * input,output(find) < forward(square) < bidirectioanl(reverse) < random(sort)
 * Design tips: most efficient alg, weakest iterator
 */
#include <stdlib.h> // std::ptrdiff_t
#include <cstddef> 
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * Forward iterator example
 * in this case, no need to use bidirectional iterator
 */
template <class Forward>
void square(Forward first, Forward last) {
  for(; first != last; ++first) {
    *first = (*first) * (*first);
  }
}

/**
 * Bidirectional iterator example
 * in this case, no need to use random access iterator
 */
template <class Bidirectional>
bool is_palindrome(Bidirectional first, Bidirectional last) {
  while(1) {
    last--;
    if(first == last) break;
    if(*first != *last) return false;
    first ++;
    if(first == last) break;
  }
  return true;
}

/**
 * Random iterator example
 * in this case, more space may be used
 */
 template <class RandomAccess>
 RandomAccess pick_rand_ei(RandomAccess first, RandomAccess last) {
   //auto temp = last - first; 
   std::ptrdiff_t temp = last - first;
   return first + rand() % temp;
 }

 int main(int argc, char *argv[]) 
 {
   string s1 = "otto";
   string s2 = "dalmatian";
   cout << is_palindrome(s1.begin(), s1.end()) << endl;
   cout << is_palindrome(s2.begin(), s2.end()) << endl;
   vector<double> w = {1., 2., 3., 4., 5.};
   cout << *pick_rand_ei(w.begin(), w.end()) << endl;
   return 0;
 }
