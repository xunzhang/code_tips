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
	// x 4 y 7  xor is reversible : tmp = x ^ y; y = tmp ^ x; x = tmp ^ y;
	printf("%d\n", (4 ^ 7) ^ (7 ^ (4 ^ 7))); // x = (x ^ y) ^ (y ^ (x ^ y))
	printf("%d\n", 7 ^ (4 ^ 7)); // y = y ^ (x ^ y)
}
