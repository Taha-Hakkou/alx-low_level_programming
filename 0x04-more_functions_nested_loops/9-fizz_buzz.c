#include <stdio.h>
/**
 * main - prints the numbers from 1 to 100 (replace with "Fizz" & "Buzz")
 *
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("Fizz");
			if (i % 5 == 0)
				printf("Buzz");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("%d", i);
		}
		if (i != 100)
			putchar(' ');
	}
	printf("\n");
	return (0);
}
