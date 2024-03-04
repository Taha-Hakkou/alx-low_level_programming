#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs simple operations
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	int (*f)(int, int);
	int a, b;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	f = get_op_func(argv[2]);
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if ((f == op_div || f == op_mod) && b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", f(a, b));
	return (0);
}
