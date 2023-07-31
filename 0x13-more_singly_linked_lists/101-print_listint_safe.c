#include "lists.h"
#include <stddef.h>
#include <stdio.h>
/**
 * print_listint_safe - prints a listint_t linked list
 * @head: a const pointer to first node of linked list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *sp, *fp;
	size_t n = 0;

	sp = head;
	fp = head;
	while (fp != NULL && fp->next != NULL)
	{
		printf("[%p] %d\n", (void *)sp, sp->n);
		sp = sp->next;
		fp = fp->next->next;
		n++;
		if (sp == fp)
		{
			fp = head;
			while (sp != fp)
			{
				printf("[%p] %d\n", (void *)sp, sp->n);
				sp = sp->next;
				fp = fp->next;
				n++;
			}
			printf("-> [%p] %d\n", (void *)sp, sp->n);
			return (n);
		}
		/* exit 98 ? */
	}
	while (sp != NULL)
	{
		printf("[%p] %d\n", (void *)sp, sp->n);
		sp = sp->next;
		n++;
	}
	return (n);
}
