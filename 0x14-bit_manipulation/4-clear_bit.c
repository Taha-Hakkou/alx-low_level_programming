#include "main.h"
#include <limits.h>
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: decimal number
 * @index: index of bit to set to 0
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1;

	for (; index > 0; index--)
		m *= 2;
	m = ULONG_MAX - m;
	*n = *n & m;
	return (1); /* return */
}
