/* Power.c */
#include <stdio.h>
#include <math.h>
double Sqrt(double val) {

  double low = 0, high = val, middle = val / 2;
  while(fabs(middle * middle - val) >= 0.00001) {
    middle = (low + high) / 2;
    if(middle * middle > val)
      high = middle;
    if(middle * middle < val)
      low = middle; 
  }
  return middle;
}

double power(double val, int n) {
  if(n == 0)
    return 1;
  if(n == 1)
    return val;

  int temp;
  temp = power(val, n / 2);
  temp *= temp;
  if(n % 2 == 0)
    return temp;
  else
    return val * temp;
  return -1;
}

double power_loop(double val, int n) {
  if(n == 0)
    return 1;
  if(n == 1)
    return val;

  double result = 1;
  while(n - 1) {
    if(n % 2 != 0)
      result *= val; 
    val *= val; 
    n /= 2;
  }
  return result * val;
}

int main(void)
{
  printf("%lf\n", power(2,3));
  printf("%lf\n", power_loop(2,4));
  printf("%lf\n", Sqrt(2));
  return 0;
}
