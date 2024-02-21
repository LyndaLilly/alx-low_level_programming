#include "hash_tables.h"

/**
 * hash_table_print - this is how to print hash table
 * @ht: this is the hash table
 * Description: Key or value pairs is printed.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *xy;
	unsigned long int pt;
	unsigned char mn = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (pt = 0; pt < ht->size; pt++)
	{
		if (ht->array[pt] != NULL)
		{
			if (mn == 1)
				printf(", ");

			xy = ht->array[pt];
			while (xy != NULL)
			{
				printf("'%s': '%s'", xy->key, xy->value);
				xy = xy->next;
				if (xy != NULL)
					printf(", ");
			}
			mn = 1;
		}
	}
	printf("}\n");
}
