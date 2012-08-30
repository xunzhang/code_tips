/* Permutation.c */
#include <stdio.h>

void swap(int *a, int *b) {
  int tmp;
  tmp = *a; *a = *b; *b = tmp;
}

void perm(int *arry, int indx, int len, int size) {
  int i;
  if(len == 1) {
    for(i = 0; i < size; ++i)
      printf("%d", arry[i]);
    printf("\n");
    return; 
  }
  for(i = 0; i < len; ++i) {
    swap(&arry[indx], &arry[indx + i]);
    perm(arry, indx + 1, len - 1, size);
    swap(&arry[indx], &arry[indx + i]);
  }
}

int main(void)
{
  int a0[3] = {1, 2, 3};
  int a[4] = {1, 2, 3, 4};
  perm(a, 0, 3, 3);
  return 0;
}
