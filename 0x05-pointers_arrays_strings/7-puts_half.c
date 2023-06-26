#include "main.h"
/**
 * puts_half - prints half of a string, followed by a new line
 * @str: a pointer to string
 */
void puts_half(char *str)
{
	int i;
	char *p;

	p = str;
	while (*p != '\0')
		p++;
	for (i = ((p - str + 1) / 2); i < (p - str); i++)
		_putchar(*(str + i));
	_putchar('\n');
}
