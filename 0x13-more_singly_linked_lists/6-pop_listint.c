#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: a pointer to a pointer to the head of linked list
 * Return: the head node’s data (n), & 0 if linked list is empty
 */
int pop_listint(listint_t **head)
{
	int n = 0;
	listint_t *l;

	if (*head != NULL)
	{
		n = (*head)->n;
		l = *head;
		*head = (*head)->next;
		free(l);
	}
	return (n);
}
