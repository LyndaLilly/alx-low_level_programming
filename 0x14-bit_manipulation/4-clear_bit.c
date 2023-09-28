#include <stdio.h>
#include "main.h"
/**
 * clear_bit - sets the value of 0
 * @n: pointer to no to chng
 * @index: is the index, starting from 0 of the bit you want to set
 * Return: 1 if it worked, or -1 if an error occurred
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
