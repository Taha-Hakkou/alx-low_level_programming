#include "function_pointers.h"
/**
 * int_index - searches for an integer
 * @array: array to search in
 * @size: size of array
 * @cmp: a pointer to the function to be used to compare values
 *
 * Return: the index of the first element
 *	   (-1) if no element matches OR size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0)
		return (-1);
	if (array != NULL || cmp != NULL)
	{
		while (!cmp(array[i]))
		{
			if (i == size)
				return (-1);
			i++;
		}
	}
	return (i);
}
