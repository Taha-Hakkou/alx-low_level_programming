#include <stdio.h>
/**
 * main - prints the number of args passed, followed by a newline
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argv; /* Ignore argv */
	printf("%d\n", argc - 1);
	return (0);
}
