/* 

  Kahan_summation.c 
  example:
  10000.0 + 3.14159 + 2.71828 = 10005.85987 = 10005.9 
  != 10003.1 + 2.71828 = 10005.8

  Notice: c rep carry.

  Another solution: d-a-c(reduce the number of times to the operatation such as "10000.0+0.12345"), 
  less accurate but no more comptation brought in.

*/

#include <stdio.h>

double KahanSum(double *a, int len) {
  int i;
  double y, c, t, sum;
  sum = 0.0;
  c = 0.0;
  for(i = 0; i < len; ++i) {
    y = a[i] - c; 
    t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }
  return sum;
}

int main(void)
{
  double a[3] = {10000.0, 3.14159, 2.71828};
  //printf("%0.1f\n", 10000.0 + 3.1415926 + 2.71828);
  printf("%0.1f\n", KahanSum(a, 3));
  return 0;
}
