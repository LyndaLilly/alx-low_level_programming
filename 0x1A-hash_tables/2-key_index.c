#include "hash_tables.h"

/**
 * key_index - this is the index key
 * @key: this is the key
 * @size: Tis is the key value size
 * Return: key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
