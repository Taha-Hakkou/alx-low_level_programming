#include "lists.h"
#include <stddef.h>
/**
 * reverse_listint - reverses a listint_t linked list
 * @head: a pointer to a pointer to head of linked list
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *l, *lx;

	l = *head;
	*head = NULL;
	while (l != NULL)
	{
		lx = *head;
		*head = l;
		l = l->next;
		(*head)->next = lx;
	}
	return (*head);
}
