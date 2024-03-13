#include "search_algos.h"
/**
 * advanced_binary - searches for a value in a sorted array of integers
 *		     using binary search
 * @array: pointer to first element in tha array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located (first occurence),
 *	   otherwise -1 if array is NULL or if value not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int index;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array:");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf(" %d\n", array[i]);
		else
			printf(" %d,", array[i]);
	}
	if (array[0] == value)
		return (0);
	if (array[(size - 1) / 2] >= value)
		return (advanced_binary(array, (size + 1) / 2, value));
	index = advanced_binary(&array[(size + 1) / 2], size / 2, value);
	if (index != -1)
		index += (size + 1) / 2;
	return (index);
}
