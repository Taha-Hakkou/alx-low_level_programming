#include "main.h"
/**
 * is_prime_number - check if a number is prime
 * @n: number
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0
 */
int is_prime_number(int n)
{
	if (n % 2 == 0 && n != 2)
		return (0);
	else
		return (is_prime_number());
}
