#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * delete_nodeint_at_index - deletes the node at index index of a listint_t
 * @head: a pointer to a pointer to the head of linked list
 * @index: the index of the node that should be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node;
	listint_t *tmp = *head;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
	}
	for (i = 0; i < index - 1; i++)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			return (-1);
	}
	node = tmp->next;
	tmp->next = tmp->next->next;
	free(node);
	return (1);
}
