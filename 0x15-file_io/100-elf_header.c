#include "main.h"
#include <elf.h>
#include <string.h>
#include <stdio.h>

void checkElf(unsigned char *elf_ident);
void printMagic(unsigned char *elf_ident);
void printClass(unsigned char *elf_ident);
void printData(unsigned char *elf_ident);
void printVersion(unsigned char *elf_ident);
void printAbi(unsigned char *elf_ident);
void printOsabi(unsigned char *elf_ident);
void printType(unsigned int elf_type, unsigned char *elf_ident);
void printEntry(unsigned long int elf_entry, unsigned char *elf_ident);
void closeElf(int elf);

/**
 * checkElf - Checks if a file is an ELF file.
 * @elf_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void checkElf(unsigned char *elf_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (elf_ident[idx] != 127 &&
		    elf_ident[idx] != 'E' &&
		    elf_ident[idx] != 'L' &&
		    elf_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagic - Prints the magic numbers of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printMagic(unsigned char *elf_ident)
{
	int idx;

	printf("  Magic:   ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", elf_ident[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printClass - Prints the class of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void printClass(unsigned char *elf_ident)
{
	printf("  Class:                             ");

	switch (elf_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * printData - Prints the data of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void printData(unsigned char *elf_ident)
{
	printf("  Data:                              ");

	switch (elf_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * printVersion - Prints the version of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF version.
 */
void printVersion(unsigned char *elf_ident)
{
	printf("  Version:                           %d",
	       elf_ident[EI_VERSION]);

	switch (elf_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * printOsabi - Prints the OS/ABI of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF version.
 */
void printOsabi(unsigned char *elf_ident)
{
	printf("  OS/ABI:                            ");

	switch (elf_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
	}
}

/**
 * printAbi - Prints the ABI version of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF ABI version.
 */
void printAbi(unsigned char *elf_ident)
{
	printf("  ABI Version:                       %d\n",
	       elf_ident[EI_ABIVERSION]);
}

/**
 * printType - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void printType(unsigned int elf_type, unsigned char *elf_ident)
{
	if (elf_ident[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * printEntry - Prints the entry point of an ELF header.
 * @elf_entry: The address of the ELF entry point.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void printEntry(unsigned long int elf_entry, unsigned char *elf_ident)
{
	printf("  Entry point address:               ");

	if (elf_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			  ((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * closeElf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void closeElf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int opn, rd;

	opn = open(argv[1], O_RDONLY);
	if (opn == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeElf(opn);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(opn, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		closeElf(opn);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkElf(header->e_ident);
	printf("ELF Header:\n");
	printMagic(header->e_ident);
	printClass(header->e_ident);
	printData(header->e_ident);
	printVersion(header->e_ident);
	printOsabi(header->e_ident);
	printAbi(header->e_ident);
	printType(header->e_type, header->e_ident);
	printEntry(header->e_entry, header->e_ident);

	free(header);
	closeElf(opn);
	return (0);
}
