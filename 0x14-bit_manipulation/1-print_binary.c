#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints a number in binary notation
 * @n: number to print
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int bit_count = sizeof(unsigned long int) * 8;
	int i;

	for (i = bit_count - 1; i >= 0; i--)
	{
		unsigned long int mask = 1UL << i;

		putchar((n & mask) ? '1' : '0');
	}
}
