#include <stdio.h>
/**
 * main - prints first 98 fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	unsigned long int fa = 1, fb = 2, fa1, fa2, fb1, fb2, l;

	l = 1000000000000;
	printf("%lu", fa);
	i = 2;
	while (i <= 98 && fb < l)
	{
		printf(", %lu", fb);
		fb += fa;
		fa = fb - fa;
		i++;
	}
	fa1 = fa / l;
	fa2 = fa % l;
	fb1 = fb / l;
	fb2 = fb % l;
	while (i <= 98)
	{
		printf(", %lu", fb1 + fb2 / l);
		printf("%012lu", fb2 % l);
		fb1 += fa1;
		fa1 = fb1 - fa1;
		fb2 += fa2;
		fa2 = fb2 - fa2;
		i++;
	}
	putchar('\n');
	return (0);
}
