#include "search_algos.h"
/**
 * binary_search - searches for a value in a sorted array of integers
 *		   using the Binary search algorithm
 * @array: pointer to first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located,
 *	   otherwise -1 if value not found or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	int i, index;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array:");
	for (i = 0; (size_t)i < size; i++)
	{
		if ((size_t)i == size - 1)
			printf(" %d\n", array[i]);
		else
			printf(" %d,", array[i]);
	}
	index = (size - 1) / 2;
	if (array[index] == value)
		return (index);
	else if (array[index] > value)
		return (binary_search(array, (size_t)index, value));
	i = binary_search(&array[index + 1], size - (size_t)index - 1, value);
	if (i != -1)
		return (i + index + 1);
	return (-1);
}
