#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_strings - prints strings, followed by a new line
 * @separator: string to be printed between the strings
 * @n: the number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *s;

	va_start(ap, n);
	if (separator == NULL)
		separator = "";
	for (i = 0; i < n - 1; i++)
	{
		s = va_arg(ap, char*);
		if (s)
			printf("%s%s", s, separator);
		else
			printf("(nil)%s", separator);
	}
	printf("%s\n", va_arg(ap, char*));
	va_end(ap);
}
