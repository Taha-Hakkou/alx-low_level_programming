#include "lists.h"
#include <stddef.h>
/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: a pointer to head of linked list
 * Return: sum of all data (n), & 0 if list is empty
 */
int sum_listint(listint_t *head)
{
	listint_t *node;
	int sum = 0;

	for (node = head; node != NULL; node = node->next)
		sum += node->n;
	return (sum);
}
