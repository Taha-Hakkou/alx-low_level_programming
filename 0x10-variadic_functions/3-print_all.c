#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i, j;
	char *v_types;
	char *fs = "\%x";

	v_types = "cifs";
	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		j = 0;
		while (format[i] != v_types[j] && j < 3)
			j++;
		if (format[i] == v_types[j])
			printf("%%c", v_types[j], va_arg(ap, int));
		i++;
	}
	va_end(ap);
}
