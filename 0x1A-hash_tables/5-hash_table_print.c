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
	char *sep;

	if (!ht)
		return;
	sep = "";
	putchar('{');
	for (i = 0; i < ht->size; i++) /* order of appearance */
		for (tmp = ht->array[i]; tmp; tmp = tmp->next)
		{
			printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
			sep = ", ";
		}
	printf("}\n");
}
