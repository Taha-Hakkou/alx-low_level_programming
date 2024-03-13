#include "search_algos.h"
/**
 * interpolation_search - searches for a value in a sorted array of integers
 *			  using the Interpolation search algorithm
 * @array: pointer to first element of the array to search in
 * @size: number of elements of array
 * @value: value to serch for
 * Return: first index where value is located,
 *	   otherwise -1 if array is NULL or if value not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL || size == 0)
		return (-1);
	low = 0;
	high = size - 1;
	while (high >= low)
	{
		pos = low + (((double)(high - low) / (array[high] - array[low]))
				* (value - array[low]));
		if (pos > high || pos < low)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}
		else
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		else if (value > array[pos])
			low = pos + 1;
		else
			high = pos - 1;
	}
	return (-1);
}
