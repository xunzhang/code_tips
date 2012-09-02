/* Ser_Sum.c */
#include <stdio.h>

void print_scan(int start, int end) {
  int i;
  for(i = start; i < end; ++i)
    printf("%d\n", i);
  printf("\n");
}

void sersum(int sum) {
  int small = 1, big = 2;
  int middle = (sum + 1) / 2;
  int tsum = small + big;
  
  if(sum < 3)
    return;
  while(small < middle) {
    if(tsum == sum) 
      print_scan(small, big + 1);
    while(tsum > sum) {
      tsum -= small;
      small ++;
      if(tsum == sum) {
        print_scan(small, big + 1);
      }
    }
    big ++;
    tsum += big;
  }
}

int main(void)
{
  sersum(15);  
  return 0;
}
