#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "main.h"
/**
 * create_array - creates an array of chars,
 *		  and initializes it with a specific char
 * @size: size of the array
 * @c: character
 *
 * Return: a pointer to the array, AND NULL if it fails or size = 0
 */
char *create_array(unsigned int size, char c)
{
	char *a;

	a = malloc(size);
	if (a == NULL || size == 0)
		return (NULL);
	memset(a, c, size);
	return (a);
}
