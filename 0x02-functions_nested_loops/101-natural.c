#include <stdio.h>
/**
 * main - sum of multiples of 3 & 5 below 1024
 *
 * Return: Always 0
 */
int main(void)
{
	int i = 3;
	int sum = 0;

	while (i < 1024)
	{
		sum += i;
		i += 3;
	}
	i = 5;
	while (i < 1024)
	{
		if (i % 3 != 0)
			sum += i;
		i += 5;
	}
	printf("%d\n", sum);
	return (0);
}
