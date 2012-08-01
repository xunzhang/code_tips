/* C_language.c */

#include <stdio.h>

void f(void) {
	static int a = 3;
	static int b;
	int c;
	++a; ++b; ++c;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	printf("c=%d\n", c);
}

int b(void) {printf("3"); return 3;}
int c(void) {printf("4"); return 4;}

int main(void)
{
/*
 * Default init to static is 0 and var in stack is arbitary
 */	
	f();
	f();
	f();

/*
 * Some tips of pointer
 * 1. base addr
 * 2. equal to "a + 1 * sizeof(int)", base addr + 4
 * 3. equal to a, &a[0], base addr
 * 4. equal to "&a + 1 * sizeof(int (*)[5])", base addr + 5 * sizeof(int)
 */
	int ar[5];
	printf("%x\n", ar); 
	printf("%x\n", ar + 1);
	printf("%x\n", &ar);
	printf("%x\n", &ar + 1);
	
/*
 * disorder: decided by the compiler
 *
 */
	int z = b() + c();
	printf("%d\n", z); 
	
/*
 *	
 *
 */
	int k1 = 41;

}

