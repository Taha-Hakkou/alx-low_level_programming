#include "lists.h"
#include <stddef.h>
#include <stdio.h>
/**
 * print_list - prints all the elements of a list_t list
 * @h: a const pointer to the first node of linked list
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	const list_t *l = h;
	size_t i;

	for (i = 0; l != NULL; i++)
	{
		if (l->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", l->len, l->str);
		l = l->next;
	}
	return (i);
}
