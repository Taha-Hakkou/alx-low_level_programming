#include "lists.h"
#include <stddef.h>
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: a pointer to first node in linked list
 * Return: The address of the node where the loop starts,
 *	   or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *sp, *fp;

	sp = head;
	fp = head;
	while (fp != NULL && fp->next != NULL)
	{
		sp = sp->next;
		fp = fp->next->next;
		if (sp == fp)
		{
			fp = head;
			while (sp != fp)
			{
				sp = sp->next;
				fp = fp->next;
			}
			return (sp);
		}
	}
	return (NULL);
}
