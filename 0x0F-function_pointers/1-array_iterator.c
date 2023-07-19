#include "function_pointers.h"
/**
 * array_iterator - executes a function given as a parameter
 *		    on each element of an array
 * @array: array to loop through
 * @size: size of array
 * @action: a pointer to the function to execute
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
			action(array[i]);
	}
}
