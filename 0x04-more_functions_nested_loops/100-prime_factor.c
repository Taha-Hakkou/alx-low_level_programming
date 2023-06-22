#include <stdio.h>
#include <math.h>
/**
 * main - prints the largest prime factor of a number
 *
 * Return: Always 0
 */
int main(void)
{
	long int n, pf, i;

	n = 612852475143;
	pf = -1;
	while (n % 2 == 0)
	{
		pf = 2;
		n /= 2;
	}
	for (i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			pf = i;
			n = n / i;
		}
	}
	if (n > 2)
	pf = n;
	printf("%ld\n", pf);
	return (0);
}
