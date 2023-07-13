#include <stdlib.h>
#include <stddef.h>
#include "main.h"
/**
 * malloc_checked - allocates memory using malloc with check
 * @b: size of memory to allocate
 *
 * Return: address to allocated memory,
 *	   OR causesprocess termination with 98 exit status
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);
	else
		return (p);
}
