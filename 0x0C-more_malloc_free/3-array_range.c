#include <stddef.h>
#include <stdlib.h>
#include "main.h"
/**
 * array_range - creates an array of integers
 * @min: minimum of range (included)
 * @max: maximum of range (included)
 *
 * Return: pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *d, i;

	if (min > max)
		return (NULL);
	d = malloc((max - min + 1) * sizeof(*d));
	if (d != NULL)
	{
		for (i = min; i <= max; i++)
			d[i - min] = i;
	}
	return (d);
}
