#include <stdio.h>
/**
 * main - prints first 50 fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	unsigned long int num1 = 1, num2 = 2, fib;

	printf("1, 2, ");
	for (i = 2; i < 50; i++)
	{
		fib = num1 + num2;
		printf("%lu", fib);
		if (i == 49)
			break;
		putchar(',');
		putchar(' ');
		num1 = num2;
		num2 = fib;
	}
	putchar('\n');
	return (0);
}
