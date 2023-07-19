#include "3-calc.h"

/**
 * op_add - adds 2 numbers
 * @a: first number
 * @b: second number
 *
 * Return: the sum of a & b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - substracts 2 numbers
 * @a: first number
 * @b: second number
 *
 * Return: the difference of a & b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies 2 numbers
 * @a: first number
 * @b: second number
 *
 * Return: the product of a & b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides 2 numbers
 * @a: first number
 * @b: second number
 *
 * Return: the result of division of a by b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - divides 2 numbers
 * @a: first number
 * @b: second number
 *
 * Return: the remainder of division of a by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
