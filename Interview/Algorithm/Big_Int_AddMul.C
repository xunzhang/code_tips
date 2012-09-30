/* Big_Int_AddMul.c 
 * Notice: If size of a is not equal to size of b, convert them into 10   bit array at first!
 */
#include <stdio.h>
#define LEN 3

void big_mul(const char* a, const char* b, char* c) {
  int i, j;
  for(i = 0; i < 2 * LEN - 1; ++i) c[i] = '0';
  for(j = 0; j < LEN; j++) 
    for(i = 0; i < LEN; i++) 
      c[j + i] += (a[i] - '0') * (b[j] - '0');
  for(j = 2 * LEN - 1 - 1; j > 0; j--) {
    if(c[j] > ('0' + 10)) {
      c[j - 1] += (c[j] - '0') / 10;
      c[j] = (c[j] - '0') % 10 + '0';
    }
  }
}

void big_add(const char* a, const char* b, char* c) {
  int i;
  for(i = 0; i < LEN; ++i) { c[i] = a[i] + b[i] - '0'; }
  for(i = LEN - 1; i > 0; --i) {
    if((c[i] - '0') > 10) {
      c[i-1] += 1;
      c[i] = (c[i] - '0') % 10 + '0';
    }
  }
}

int main()
{
  char a[11] = "0123456789";
  char b[11] = "0123456789";
  char c[11];
  big_add(a, b, c);
  int i;
  for(i = 0; i < 10; ++i)
    printf("%c\t", c[i]);
  printf("\n");
  char d[4] = "149";
  char e[4] = "023";
  char f[6];
  big_mul(d, e, f);
  for(i = 0; i < 5; ++i)
    printf("%c\t", f[i]);
  printf("\n");
  return 0;
}
