#include "variadic_functions.h"
#include <stdarg.h>
#include <string.h>
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
	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, char*);
		if (s == NULL)
			s = "(nil)";
		printf("%s", s);
		if (n > 0 && i + 1 < n)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
