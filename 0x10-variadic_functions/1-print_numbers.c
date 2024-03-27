#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);
	if (separator == NULL)
		separator = "";
	for (i = 0; i + 1 < n; i++)
		printf("%d%s", va_arg(ap, int), separator);
	if (n > 0)
		printf("%d", va_arg(ap, int));
	printf("\n");
	va_end(ap);
}
