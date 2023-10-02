#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: path to the text file
 * @letters: the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n = 0;
	char str[1000];

	if (filename != NULL)
	{
		fd = open(filename, O_RDONLY);
		if (fd >= 0)
		{
			n = read(fd, str, letters);
			n = write(STDOUT_FILENO, str, (size_t)n);
			close(fd);
		}
	}
	return (n);
}
