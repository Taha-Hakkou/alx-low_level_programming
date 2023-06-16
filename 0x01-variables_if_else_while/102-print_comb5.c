#include <stdio.h>

/**
 * main - prints possible combinations of two two-digit numbers
 * Return: value 0
 */
int main(void)
{
	int i, j, k, t;

	for (i = '0'; i <= '9'; i++)
	{
		for (j = '0'; j <= '9'; j++)
		{
			for (k = i; k <= '9'; k++)
			{
				for (t = '0'; t <= '9'; t++)
				{
					if (k == i && t == '0' && j != '9')
						t = j + 1;
					else if (k == i && t == '0' && j == '9')
						break;
					if (i != '0' || j != '0' || k != '0' || t != '1')
					{
						putchar(',');
						putchar(' ');
					}
					putchar(i);
					putchar(j);
					putchar(' ');
					putchar(k);
					putchar(t);
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
