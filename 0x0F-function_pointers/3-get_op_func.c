#include "3-calc.h"
#include <stddef.h>
/**
 * get_op_func - selects the correct function to perform the operation
 * @s: pointer to operator
 *
 * Return: correct function OR NULL if wrong operator passed
 */
int (*get_op_func(char *s))(int a, int b)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (s != ops[i].op && i < 6)
		i++;
	if (i == 6)
		return (NULL);
	return (ops[i].f);
}
