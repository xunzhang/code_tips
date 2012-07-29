/* Swap.c */

#include <stdio.h>

void swap(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void swap2(int *a, int *b) {
	(*a) ^= (*b) ^= (*a) ^= (*b);
}

int main(void)
{
	int x = 3, y = 4;
	swap(&x, &y);
	printf("%d\t%d\n", x, y);

	int x2 = 3, y2 = 4;
	//swap2(&x2, &y2);
	//x2 ^= y2 ^= x2 ^= y2;
	x2 ^= y2;
	y2 ^= x2;
	x2 ^= y2;
	printf("%d\t%d\n", x2, y2);
	printf("%d\n", 7^4);
	printf("%d\n", 3^4);
}
