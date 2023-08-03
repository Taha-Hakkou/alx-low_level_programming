#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__LP64__)
#define ElfW(type) Elf64_ ## type
#else
#define ElfW(type) Elf32_ ## type
#endif

/**
 * main - displays the information contained in the ELF header
 * @ac: arguments count
 * @av: arguments vector
 * Return: ELF Header information on success, exit on failure
 */
int main(int ac, char **av)
{
	int elfd;
	char buffer[16];

	ElfW(Ehdr) header;

	if (ac != 2)
		exit(-1);
	elfd = open(av[1], O_RDONLY);
	if (elfd > 0)
	{
		read(elfd, buffer, sizeof(header));
		if (memcmp(header.e_ident, ELFMAG, SELFMAG) == 0)
		{
			printf("ELF Header:\n");
			printf("  %9s %s\n", "Magic:", "a");
			printf("  %34s %s\n", "Class:", "a");
			printf("  %34s %s\n", "Data:", "a");
			printf("  %34s %s\n", "Version:", "a");
			printf("  %34s %s\n", "OS/ABI:","a" );
			printf("  %34s %s\n", "ABI Version:","a" );
			printf("  %34s %s\n", "Type:","a" );
			printf("  %34s %s\n", "Entry point address:", "a");
		}
		close(elfd);
	}
	return (0);
}
