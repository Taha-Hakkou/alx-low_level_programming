#include <stdio.h>
/**
 * main - prints first 98 fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int e = 1, f = 2;
	unsigned long int i, l = 1000000000;
	unsigned long int e1, e2, f1, f2;

	printf("%lu", e);
	for (i = 1; i < 91; i++)
	{
		printf(", %lu", f);
		f += e;
		e = f - e;
	}
	e1 = (e / l);
	e2 = (e % l);
	f1 = (f / l);
	f2 = (f % l);
	for (i = 92; i < 99; ++i)
	{
		printf(", %lu", f1 + (f2 / l));
		printf("%lu", f2 % l);
		f1 = f1 + e1;
		e1 = f1 - e1;
		f2 = f2 + e2;
		e2 = f2 - e2;
	}
	printf("\n");
	return (0);
}
