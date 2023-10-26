#include <stdio.h>
#include "main.h"
/**
 * get_endianness - checks if a machine is little or big endia
 * Return: 0 or 1
 */
int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char *byte_ptr = (unsigned char *)&num;

	return ((int)(*byte_ptr));
}

