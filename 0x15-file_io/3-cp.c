#include "main.h"
#include <stdio.h>

/**
 * errfile - checks if files can be opened.
 * @ffrom: file_from.
 * @fto: file_to.
 * @argv: arguments vector.
 * Return: no return.
 */
void errfile(int ffrom, int fto, char *argv[])
{
	if (ffrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (fto == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: arguments count
 * @av: arguments vector
 * Return: 0 on Success, exit with error_code on errors
 */
int main(int argc, char *argv[])
{
	int ffrom, fto, err_close;
	ssize_t nchars, nwrite;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	ffrom = open(argv[1], O_RDONLY);
	fto = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	errfile(ffrom, fto, argv);
	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(ffrom, buffer, 1024);
		if (nchars == -1)
			errfile(-1, 0, argv);
		nwrite = write(fto, buffer, nchars);
		if (nwrite == -1)
			errfile(0, -1, argv);
	}
	err_close = close(ffrom);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ffrom);
		exit(100);
	}
	err_close = close(fto);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ffrom);
		exit(100);
	}
	return (0);
}
