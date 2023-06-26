#include "main.h"
/**
 * _puts - prints a string, followed by a newline
 * @str: a pointer to first character of the string
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
