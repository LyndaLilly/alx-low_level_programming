#include <stdio.h>
#include "main.h"
/**
 * clear_bit - sets the value
 * @n: pointer to no to chng
 * @index: is the index of bit to change
 * Return: 1 or -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = ~(1UL << index);

	*n = *n & mask;
	return (1);
}
