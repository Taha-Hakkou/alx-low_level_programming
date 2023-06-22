#include "main.h"
/**
 * more_numbers - prints the numbers from 0 to 14 (10 times)
 */
void more_numbers(void)
{
	int i, d, t = 0, n = 14;

	for (i = 1; i <= 10; i++)
	{
		for (d = 0; d <= n; d++)
		{
			if (t != 0)
				_putchar(t + '0');
			_putchar(d + '0');
			if (d == 9)
			{
				d = -1;
				n -= 10;
				t++;
			}
		}
		n += (t * 10);
		t = 0;
		_putchar('\n');
	}
}
