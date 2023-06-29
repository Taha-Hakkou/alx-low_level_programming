#include "main.h"
/**
 * reverse_array - reverses the content of an array of integers
 * @a: a pointer to the first element of the array
 * @n: number of elements of the array
 */
void reverse_array(int *a, int n)
{
	int i;
	int tmp;

	for (i = 0; i < n--; i++)
	{
		tmp = a[i];
		a[i] = a[n];
		a[n] = tmp;
	}
}
