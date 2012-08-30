/* Itoa.c */
#define MAX 3

char out[MAX];

void itoa(int num) {
  int flag = 0;
  char tmp[MAX];
  if(num < 0) {
    num *= -1;
    flag = 1;
  }
  
  int i = 0;
  do{  
    tmp[i++] = (char) (num % 10 + '0');
    num /= 10;
  }while(num != 0);
  
  if(flag)
    tmp[i++] = '-';
  
  int j = 0;
  while(i > 0)
    out[j++] = tmp[--i];
}

int main(void)
{
  itoa(234);
  printf("%s\n", out);
  return 0;
}

