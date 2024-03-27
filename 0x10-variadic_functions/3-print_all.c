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
	int i = 0;
	char *s;

	if (format)
	{
		va_start(ap, format);
		while (format[i])
		{
			switch (format[i])
			{
			case 'c':
			case 'i':
				printf(format[i] == 'c' ? "%c" : "%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
				s = va_arg(ap, char*);
				switch (*s)
				{
				case 0:
					printf("(nil)");
					break;
				default:
					printf("%s", s);
				}
				break;
			default:
				i++;
				continue;
			}
			if (format[++i])
				printf(", ");
		}
	}
	printf("\n");
	va_end(ap);
}
