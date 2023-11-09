#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index of a dlistint_t linked list
 * @head: pointer to pointer to head node
 * @index: index of the node that should be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i;

	if (!(*head))
		return (-1);
	if (!index)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	i = 1;
	for (tmp = *head; tmp->next; tmp = tmp->next)
	{
		if (i == index)
		{
			if (tmp->next->next)
			{
				tmp->next = tmp->next->next;
				free(tmp->next->prev);
				tmp->next->prev = tmp;
			}
			else
			{
				free(tmp->next);
				tmp->next = NULL;
			}
			return (1);
		}
		i++;
	}
	return (-1);
}
