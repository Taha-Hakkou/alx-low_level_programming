#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 *		print key/value in order they appear in hash table's array
 *		(order: array, list)
 *		if ht is NULL, don't print anything
 * @ht: hash table to print
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;
	int x = 0;

	if (ht)
	{
		putchar('{');
		/* array */
		for (i = 0; i < ht->size; i++) /* order of appearance */
		{
			tmp = ht->array[i];
			if (tmp)
			{
				if (x)
					printf(", ");
				else
					x = 1;
				printf("'%s': '%s'", tmp->key, tmp->value);
			}
		}
		/* list */
		for (i = 0; i < ht->size; i++)
		{
			tmp = ht->array[i];
			if (tmp)
				while (tmp->next)
				{
					tmp = tmp->next;
					printf("'%s': '%s', ", tmp->key, tmp->value);
				}
		}
		printf("}\n");
	}
}
