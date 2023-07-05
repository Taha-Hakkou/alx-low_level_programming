#include "main.h"
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 *
 * Return: -1 if (n < 0 || sqrt(n) isn't natural), sqrt(n) otherwise
 */
int _sqrt_recursion(int n)
{
	int i;

	if (n < 0)
		return (-1);
	return (recursion(n, 0));
}

/**
 * recursion - recurses to find the natural
 * square root of a number
 * @n: number to calculate the sqaure root of
 * @i: iterator
 *
 * Return: the resulting square root
 */
int recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (recursion(n, i + 1));
}

