#include "lists.h"
#include <stddef.h>
/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: a pointer to the head of the linked list
 * @index: the index of the node, starting at 0
 * Return: the nth node of linked list, & NULL if node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node;
	unsigned int i;

	node = head;
	for (i = 0; i < index; i++)
	{
		if (node->next != NULL)
			node = node->next;
		else
			return (NULL);
	}
	return (node);
}
