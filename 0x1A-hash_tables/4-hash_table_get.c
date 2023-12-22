#include "hash_tables.h"
/**
 *hash_table_get - this is how to get hash table
 *@ht: this is the hash table
 *@key: this is the key
 *Return: value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t *p;
unsigned long int xy;

if (key == NULL || ht == NULL)
return (NULL);

xy = key_index((const unsigned char *)key, ht->size);
p = ht->array[xy];

for (; p != NULL; p = p->next)
{
if (strcmp(p->key, key) == 0)
return (p->value);
}
return (NULL);
}
