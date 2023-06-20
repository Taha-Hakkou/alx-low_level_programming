#include <stdio.h>
/**
 * main - prints sum of 'even' fibonacci numbersthat not exceed 4000000
 *
 * Return: Always 0
 */
int main(void)
{
	int num1 = 1, num2 = 2, fib = 2, sum = 0;

	while (fib <= 4000000)
	{
		if (fib % 2 == 0)
			sum += fib;
		fib = num1 + num2;
		num1 = num2;
		num2 = fib;
	}
	printf("%d\n", sum);
	return (0);
}
