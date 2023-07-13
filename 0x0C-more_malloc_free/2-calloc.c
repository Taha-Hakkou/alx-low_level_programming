#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of array elements
 * @size: size of each element
 *
 * Return: a pointer to allocated memory,
 *	   or NULL if allocation fails OR (nmemb == 0 || size == 0)
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p != NULL)
		memset(p, 0, nmemb * size);
	return (p);
}
