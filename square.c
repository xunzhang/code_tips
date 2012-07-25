/* square.c */
#include <stdio.h>

int square(int n) {
	int i, res = 1, x = 1, dx = 1;
	for(i = 1; i < n; ++i) {
		dx += 2;
		x += dx;	
		res = x;
	}
	return res;	
}

int main(void) 
{
	printf("%d\n", square(100));
	return 0;
}
