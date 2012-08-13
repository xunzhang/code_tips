/* Shuf_Knuth.c */
#include <stdio.h>
#include <stdlib.h>

/* bigrand is useful when RAND_MAX is less than INT_MAX, or bigrand() may be a negative value.*/
int bigrand(){
  return (RAND_MAX * rand() + rand());
}

/* Knuth version, the best. */
void ShufKnuth(int m, int n) {
  int i;
  srand((unsigned int)time(NULL));
  for(i = 0; i < n; ++i) { // sorted & distinguished & fair
    if(rand() % (n - i) < m) { // make sure m nums, think about it in extreme cases
      printf("%d\n", i);
      m --;
    }
  }
}

int randint(int l, int u) {
  srand((unsigned)time(NULL));
  return l + rand() % (u - l + 1);
}

/* Another version based on the original "Knuth-Fisher-Yates shuffle algorithm", a little regid. Time complexity is O(n+mlogm) and space complexity is O(n). */
void GenShuf(int m, int n) {
  int i, j, tmp;
  int *x = (int *)malloc(n*sizeof(int)); // n size of memory
  for(i = 0; i < n; ++i) x[i] = i;
  for(i = 0; i < m; ++i) { // O(n)
    j = randint(i, n - 1);
    tmp = x[i]; x[i] = x[j]; x[j] = tmp;
  }
  // sort(x, x+m); // O(mlogm)
  for(i = 0; i < m; ++i)
    printf("%d\n", x[i]);
}

/* Recursion version, take care of stackoverflow:). */
void randselect(int m, int n) {
  if(m > 0) 
  if(rand() % n < m) {
    randselect(m - 1, n - 1);
    printf("%d\n", n - 1);
  }
  else
    randselect(m, n - 1);
}

int main(void)
{
  ShufKnuth(3, 10);
  GenShuf(3, 10);
  randselect(3, 10); 
  return 0;
}
