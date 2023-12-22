#include "hash_tables.h"

/**
 * hash_djb2 - this is the hash djb2
 * @str: this is the string
 * Return: This is the key
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long st = 5381;
	int x;

	while ((x = *str++))
	st = ((st << 5) + st) + x;

	return (st);
}
