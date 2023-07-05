#include "main.h"

int recursion(int n, int i);

/**
 * is_prime_number - check if a number is prime
 * @n: number
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else
		return (recursion(n, 2));
}

/**
 * recursion - recurses on possible factors
 * @n: number
 * @i: index
 *
 * Return: 1 if prime, otherwise 0
 */
int recursion(int n, int i)
{
	if (n % i == 0)
		return (0);
	return (recursion(n, i + 1));
}
