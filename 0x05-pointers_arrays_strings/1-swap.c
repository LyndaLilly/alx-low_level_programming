#include "main.h"
/**
 * swap_int - swaps the values of two integers
 * @a: Integer to swap
 * @b: Integer to swap
 */
void swap_int(int *a, int *b)
{
	int m;

	m = *a;
	*a = *b;
	*b = m;
}
