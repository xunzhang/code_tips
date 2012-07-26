/* Square.c */
#include <stdio.h>

int square(int n) {
	int a = 0, b = 1;	
	while(n--) {
		a += b;
		b += 2;	
	}
	return a;
}

int main(void) 
{
	printf("%d\n", square(100));
	return 0;
}
