#include <stdio.h>
#include "main.h"
/**
 * get_bit - this gets the bit number
 * @n: num of bit to get
 * @index:  the index of bit to get
 * Return: -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bitmask;

	if (index > 63)
		return (-1);
	bitmask = (n >> index) & 1;
	return (bitmask);
}
