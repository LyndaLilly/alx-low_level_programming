#include <stdio.h>
#include "main.h"
/**
 * binary_to_uint - this converts binary to int unit
 * @b: this is the binary number
 * Return: 0
 */
unsigned int binary_to_uint(const char *b)
{
	int c;
	unsigned int result;

	result = 0;
	if (!b)
		return (0);
	for (c = 0; b[c] != '\0'; c++)
	{
		if (b[c] != '0' && b[c] != '1')
			return (0);
	}
	for (c = 0; b[c] != '\0'; b++)
	{
		result <<= 1;
		if (b[c] == '1')
			result += 1;
	}
	return (result);
}
