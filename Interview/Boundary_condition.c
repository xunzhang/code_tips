/* Boundary_condition.c */
#include <stdio.h>

int main(void)
{
	int i, a[10];
	printf("%p\t%p\n", &a[10], &i);
	// endless loop &a[10] == &i
	for(i = 0; i <= 10; ++i) {
		a[i] = 0;
	}
	return 0;
}
