#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * free_listint_safe - frees a listint_t list safely
 * @h: a pointer to a pointer to head of linked list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *sp, *fp, *node;
	size_t n = 0;

	node = *h;
	sp = fp = node;
	while (fp && fp->next)
	{
		if (sp->next == fp->next->next)
		{
			sp->next = NULL;
			break;
		}
		sp = sp->next;
		fp = fp->next->next;
	}
	while (node)
	{
		sp = node->next;
		free(node);
		n++;
		node = sp;
	}
	*h = NULL;
	return (n);
}
