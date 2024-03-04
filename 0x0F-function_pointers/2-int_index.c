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
	int i, idx = 0;

	if (array == NULL || cmp == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (idx);
		idx++;
	}
	return (-1);
}
