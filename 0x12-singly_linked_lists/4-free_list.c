#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * free_list - frees a list_t list
 * @head: a pointer to first node of the linked list
 */
void free_list(list_t *head)
{
	list_t *node;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node->str);
		free(node);
	}
}
