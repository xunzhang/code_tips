/* Matrix_Chain_Mul.c */
#include <stdio.h>
#include <stdlib.h>
#define indx(tmp, i, j) (*(tmp + ((j + 1) * i) + j))

int matrix_chain_order(int* size_lst, int result[6][6], int s[6][6], int n) {
  int i = 0, l = 0, j = 0, k = 0;  
  int tmp = 0;
  for(; i < n; ++i)  
    result[i][i] = 0;
  for(l = 1; l < n; ++l) { // length of m[i, j]
    for(i = 0; i < n - l; ++i) { // for each length, consider the start index
      j = i + l;
      result[i][j] = 1000000;
      for(k = i; k < j; ++k) {
        // printf("%d\t%d\t%d\n", i, k + 1, j + 1);
        tmp = result[i][k] + result[k + 1][j] + size_lst[i] * size_lst[k + 1] * size_lst[j + 1];
        if(tmp < result[i][j]) { 
          result[i][j] = tmp;
          s[i][j] = k;
        }
      }
    }
  } 
}	

void tty(int *tmp) {
  printf("%d\n", indx(tmp, 1, 1));
}	
	
int main(void)
{
  int a[7] = {5, 10, 3, 12, 5, 50, 6};
  int res[6][6], s[6][6];
  matrix_chain_order(a, res, s, 6);
  printf("%d\n", res[0][5]);
  int *try = (int *)malloc(4*sizeof(int));
  try[0] = 1;
  try[1] = 2;
  try[2] = 3;
  try[3] = 4;
  tty(try);
  return 0;
}
