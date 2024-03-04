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
	while (ops[i].op)
	{
		if (*s == ops[i].op[0] && *(s + 1) == '\0')
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
