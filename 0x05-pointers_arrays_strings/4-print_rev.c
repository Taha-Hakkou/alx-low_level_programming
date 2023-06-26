#include "main.h"
/**
 * print_rev - prints a string in reverse, followed by a newline
 * @s: a pointer to first character of the string
 */
void print_rev(char *s)
{
	char *p;

	p = s;
	while (*p != '\0')
		p++;
	while (p != s)
	{
		p--;
		_putchar(*p);
	}
	_putchar('\n');
}
