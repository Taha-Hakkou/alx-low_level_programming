#include <stdio.h>

/**
 * main - prints single digit numbers of base 10
 * Return: value 0
 */
int main(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
