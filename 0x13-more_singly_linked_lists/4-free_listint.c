#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * free_listint - frees a listint_t list
 * @head: a pointer to the head of the linked list
 */
void free_listint(listint_t *head)
{
	listint_t *l;

	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		l = head;
		head = head->next;
		free(l);
	}
	free(head);
}
