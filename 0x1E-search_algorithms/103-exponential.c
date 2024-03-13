#include "search_algos.h"
/**
 * exponential_search - searches for a value in a sorted array of integers
 *			using the Exponential search algorithm
 * @array: pointer to first element of the array to search in
 * @size: number of elements of array
 * @value: value to search for
 * Return: first index where value is located,
 *	   otherwise -1 if array is NULL or if value not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t index = 1, h;
	int rvalue;

	if (array == NULL || size == 0)
		return (-1);
	if (array[0] == value)
		return (0);
	if (size == 1)
		return (-1);
	printf("Value checked array[1] = [1]\n");
	while (index * 2 < size && array[index * 2] < value)
	{
		index *= 2;
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
	}
	h = index * 2 < size ? index * 2 : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", index, h);
	rvalue = binary_search(&array[index], h - index + 1, value);
	if (rvalue != -1)
		rvalue += index;
	return (rvalue);
}

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
