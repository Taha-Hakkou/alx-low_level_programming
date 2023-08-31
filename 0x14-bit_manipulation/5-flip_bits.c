#include "main.h"
/**
 * flip_bits - count the number of bits to flip to switch number
 * @n: first number
 * @m: second number
 * Return: the number of bits to flip to get from one number to another
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x;
	unsigned int i;

	x = n ^ m;
	i = 0;
	while (x > 0)
	{
		i += x & 1;
		x = x >> 1;
	}
	return (i);
}
