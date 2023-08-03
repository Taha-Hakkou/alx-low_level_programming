#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	char s[1000];
	unsigned int i;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (filename == NULL || fd < 0)
		return (-1);
	if (text_content != NULL)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			s[i] = text_content[i];
		write(fd, s, strlen(text_content));
		close(fd);
	}
	return (1);
}
