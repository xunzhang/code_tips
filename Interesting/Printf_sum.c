/* Printf_sum.c 
 *
 * Find sum of positive integers without using any operator. Only use of printf() is allowed. No other library function can be used.
 *
 */

#include <stdio.h>

int p_sum(int x, int y) {
	return printf("%*c%*c", x, '\r', y, '\r');
}

int main(void)
{
	printf("sum is%d\n", p_sum(3,4));
}
