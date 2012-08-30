/* atoi.c */
#include <stdio.h>

int atoi(char* a, int len) {
  int i = 0, flag = 0, integer = 0;
  
  if(a[0] == '-') {
    flag = 1;
    i = 1;
  }
  
  for(; i < len - 1; ++i) 
    integer = integer * 10 + a[i] - '0'; 
  
  return flag == 1 ? -integer : integer;
}

int main(void)
{
  //char a[7] = "113579";
  char a[7] = "-13579";
  printf("%d\n", atoi(a, sizeof(a)));
  return 0;	
}
