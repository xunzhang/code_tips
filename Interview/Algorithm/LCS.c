/* LCS.c */
#include <stdio.h>
#include <stdlib.h>

void LCS(char* a, char* b, int size_a, int size_b, int result[7][7]) {
  int i = 0, j = 0, k = 0;
  for(i = 0; i < size_a; ++i) result[i][0] = 0;
  for(j = 0; j < size_b; ++j) result[0][j] = 0;
  for(i = 1; i < size_a; ++i) {
    for(j = 1; j < size_b; ++j) {
      if(a[i] == b[j])
        result[i][j] = result[i - 1][j - 1] + 1;
      else if(result[i - 1][j] > result[i][j - 1])  result[i][j] = result[i - 1][j];
           else result[i][j] = result[i][j - 1];
    }
  }  
}

int main(void)
{
  char a[7] = {'a', 'b', 'c', 'b', 'd', 'a', 'b'};
  char b[7] = {'b', 'd', 'c', 'a', 'b', 'a'};
  int res[7][7];
  LCS(a, b, 7, 7, res);
  printf("%d\n", res[6][6]);
  return 0;
}
