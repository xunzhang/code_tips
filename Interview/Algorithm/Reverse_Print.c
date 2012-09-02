/* Reverse_Print.c */
#include <stdio.h>
void rprint(char* str) {
  if(*str != '\0') {
    rprint(str + 1);
    printf("%c", *str);
  }
  return;
}

int slen(char* str) {
  if(*str != '\0')
    return 1 + slen(str + 1);
  else
    return 0;
}

int main(void)
{
  char str[] = "hello";
  rprint(str);
  printf("\n");
  printf("str's length is %d\n", slen(str));
  return 0;
}
