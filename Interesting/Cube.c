/* Cube.c */
#include <stdio.h>

int cube(int n) {
	int a = 0, b = 1, c = 6;	
	while(n--) {
		a += b;
		b += c;
		c += 6;	
	}
	return a;
}

int main(void) 
{
	printf("%d\n", cube(12));
	return 0;
}
