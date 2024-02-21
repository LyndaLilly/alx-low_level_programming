#include "hash_tables.h"

/**
 * hash_table_delete - this is how to delete hash table
 * @ht: this is the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *mn, *rt;
	unsigned long int j;

	for (j = 0; j < ht->size; j++)
	{
		if (ht->array[j] != NULL)
		{
			mn = ht->array[j];
			while (mn != NULL)
			{
				rt = mn->next;
				free(mn->key);
				free(mn->value);
				free(mn);
				mn = rt;
			}
		}
	}
	free(head->array);
	free(head);
}
