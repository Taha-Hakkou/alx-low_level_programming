#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals
 *	   of a square matrix of integers
 * @a: array of arrays of int
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i, sum1, sum2;

	sum1 = 0;
	for (i = 0; i < size; i++)
		sum1 += *(a + size * i + i);
	sum2 = 0;
	for (i = 0; i < size; i++)
		sum2 += *(a + size * i + (size - i - 1));
	printf("%d, %d\n", sum1, sum2);
}
