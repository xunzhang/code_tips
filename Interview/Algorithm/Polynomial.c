/* Polynomial.c */
#include <stdio.h>

double eval(double x, double *a, int n) {
  if(n == 1)
    return  a[0] + a[1] * x;
  else
    return a[0] + eval(x, a + 1, n - 1) * x;
}

int main(void)
{
  double a[5] = {5, 4, 3, 2, 1};
  printf("result is %lf\n", eval(0.5, a, 4));
  return 0;
}
