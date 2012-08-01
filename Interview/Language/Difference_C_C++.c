/* Difference_C_C++.c 
 *
 * compiler error by g++(no statement for printf func)
 * but, can be successfully compiled by gcc(define a default printf from compiler and the lib printf can be finded during the link step)
 * -std=c89 return 3 while -std=c99 return 0
 * main(void) is exact while main() rep main(...)   
 *
 */

int main()
{
	int a = 42;
	printf("%d\n", a);
}
