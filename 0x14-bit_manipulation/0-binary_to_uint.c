#include "main.h"
#include <stddef.h>
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 chars
 * Return: the converted number, or 0 if b is NULL or b[i] != {0,1}
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n, i;

	if (b == NULL)
		return (0);
	n = 0;
	for (i = 0; b[i] != '\0'; i++)
	{
		n = n << 1;
		if (b[i] == '0' || b[i] == '1')
			n  = n | (b[i] - '0');
		else
			return (0);
	}
	return (n);
}
