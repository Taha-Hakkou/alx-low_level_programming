#include "search_algos.h"
/**
 * jump_list - searches for a value in a sorted list of integers
 *	       using the Jump search algorithm
 * @list: pointer to head of list to search in
 * @size: number of nodes in list
 * @value: value to search for
 * Return: pointer to first node where value is located,
 *	   or NULL if head is NULL or if value not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	int sr, i;
	listint_t *node, *tmp;

	if (list == NULL)
		return (NULL);
	sr = sqrt(size);
	tmp = list;
	do {
		node = tmp;
		for (i = 0; i < sr && tmp->next; i++)
			tmp = tmp->next;
		printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
	} while (tmp->n <= value && tmp->next);
	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, tmp->index);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	do {
		if (node->n == value)
			return (node);
		node = node->next;
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	} while (node != tmp);
	return (NULL);
}
