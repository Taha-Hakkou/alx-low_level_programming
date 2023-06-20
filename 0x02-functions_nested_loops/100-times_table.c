#include "main.h"
/**
 * print_times_table - prints times table of n
 * @n: number
 */
void print_times_table(int n)
{
	int i, j, p;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				p = i * j;
				if (j == 0)
				{
					_putchar('0');
				}
				else if (p / 10 == 0)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(p + '0');
				}
				else if (p / 100 == 0)
				{
					_putchar(' ');
					_putchar(p / 10 + '0');
					_putchar(p % 10 + '0');
				}
				else
				{
					_putchar(p / 100 + '0');
					_putchar((p / 10) % 10 + '0');
					_putchar(p % 10 + '0');
				}
				if (j != n)
				{
					_putchar(',');
					_putchar(' ');
				}
			}
			_putchar('\n');
		}
	}
}
