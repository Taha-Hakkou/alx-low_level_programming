#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: decimal number
 */
void print_binary(unsigned long int n)
{
	unsigned long int bin = 1;

	while ((bin << 1) <= n)
		bin = bin << 1;
	while (bin != 0)
	{
		if (n & bin)
			_putchar('1');
		else
			_putchar('0');
		bin = bin >> 1;
	}
}
