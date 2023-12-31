#include "function_pointers.h"
/**
 * print_name - prints a name
 * @name: name to be printed
 * @f: pointer to function that will print
 */
void print_name(char *name, void (*f)(char *))
{
	if (f != NULL)
		f(name);
}
