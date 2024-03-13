#include "search_algos.h"
/**
 * jump_search - searches for a value in a sorted array of integers
 *		 using the Jump search algorithm
 * @array: pointer to first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located,
 *	   otherwise -1 if value not found or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int i, j, sr;

	if (array == NULL)
		return (-1);
	sr = sqrt(size);
	for (i = 0; (size_t)i < size; i += sr)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		else if (i + sr >= (int)size || array[i + sr] >= value)
			break;
	}
	printf("Value found between indexes [%d] and [%d]\n", i, i + sr);
	for (j = i; j < (int)size && j <= i + sr; j++)
	{
		printf("Value checked array[%d] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}
	return (-1);
}
