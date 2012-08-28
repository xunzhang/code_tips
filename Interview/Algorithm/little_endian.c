/* little_endian.c */
#include <stdio.h>
/* return 1 if little_endian, 0 if big_endian*/
int endianness() {
  int testNum;
  char *ptr;
  testNum = 1;
  ptr = (char *) &testNum;
  return *ptr;
}

int endianness_better() {
  union {
    int testInteger;
    char singleByte;
  } endianTest;
  endianTest.testInteger = 1;
  return endianTest.singleByte;
}

int main(void)
{
  printf("%d\n", endianness()); 
  printf("%d\n", endianness_better()); 
  return 0;
}
