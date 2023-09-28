#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints a number in binary notation
 * @n: number to print
 */
void print_binary(unsigned long int n)
{
	int i, j = 0;
	unsigned long int  bit_position;

	for (i = 63; i >= 0; i--)
	{
		bit_position = n >> i;

		if (bit_position & 1)
		{
			putchar('1');
			j++;
		}
		else if (j)
			putchar('0');
	}
	if (!j)
		_putchar('0');
}
