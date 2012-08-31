/* Ser_matric.c */

#include <stdio.h>
#define M 4
#define N 5

void Print_Matrix(int a[M][N], int si, int sj, int m, int n) {
  if(m == 0 || n == 0)
    return;
  int i, j;
  if(m == 1)
    for(j = 0; j < n; ++j)
      printf("%d\n", a[si][sj + j]);
  else if(n == 1)
    for(i = 0; i < m; ++i)
      printf("%d\n", a[si + i][sj]);
  else {
    for(j = 0; j < n - 1; ++j)
      printf("%d\n", a[si][sj + j]); 
    for(i = 0; i < m - 1; ++i)
      printf("%d\n", a[si + i][sj + n - 1]); 
    for(j = n - 1; j > 0; --j)
      printf("%d\n", a[si + m - 1][sj + j]); 
    for(i = m - 1; i > 0; --i)
      printf("%d\n", a[si + i][sj]); 
    
    Print_Matrix(a, si + 1, sj + 1, m - 2, n - 2);
  }
}

int main(void)
{
  int A[M][N] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
  Print_Matrix(A, 0, 0, M, N);
  return 0;
}
