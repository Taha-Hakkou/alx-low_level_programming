#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * free_listint_safe - frees a listint_t list
 * @h: a pointer to a pointer to head of linked list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *sp, *fp, *node;
	size_t n = 0;

	sp = *h;
	fp = *h;
	node = *h;
	while (fp != NULL && fp->next != NULL)
	{
		sp = sp->next;
		fp = fp->next->next;
		if (sp == fp)
		{
			fp = *h;
			node = sp;
			while (sp != fp)
			{
				free(sp);
				sp = sp->next;
				free(fp);
				fp = fp->next;
			}
			while (sp != node)
			{
				free(sp);
				sp = sp->next;
			}
		}
	}
	*h = NULL;
	return (n);
}
