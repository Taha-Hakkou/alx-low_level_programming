#include "main.h"
/**
 * print_last_digit - prints last digit of a number
 * @n: number
 *
 * Return: Always last number
 */
int print_last_digit(int n)
{
	if (n < 0)
	{
		n = (n + 1) * (-1);
		_putchar(n % 10 + '1');
		return (n % 10 + 1);
	}
	else
	{
		_putchar(n % 10 + '0');
		return (n % 10);
	}
}
