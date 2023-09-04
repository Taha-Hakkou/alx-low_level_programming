#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
/**
 * create_file - creates a file
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	char s[1000];
	unsigned int i;

	if (filename == NULL)
	{
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
		if (fd >= 0)
		{
			for (i = 0; text_content[i] != '\0'; i++)
				s[i] = text_content[i];
			write(fd, s, strlen(text_content));
			close(fd);
			return (1);
		}
	}
	return (-1);
}
