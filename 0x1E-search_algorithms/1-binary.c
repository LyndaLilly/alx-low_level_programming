#include "search_algos.h"

/**
 * recursive_search - this searches recurisively
 * @array: this is the array
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t res = size / 2;
	size_t mt;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (mt = 0; mt < size; mt++)
		printf("%s %d", (mt == 0) ? ":" : ",", array[mt]);

	printf("\n");

	if (res && size % 2 == 0)
		res--;

	if (value == array[res])
		return ((int)res);

	if (value < array[res])
		return (recursive_search(array, res, value));

	res++;

	return (recursive_search(array + res, size - res, value) + res);
}

/**
 * binary_search - this is the binary search
 * @array: this is the array
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
int binary_search(int *array, size_t size, int value)
{
	int ptr;

	ptr = recursive_search(array, size, value);

	if (ptr >= 0 && array[ptr] != value)
		return (-1);

	return (ptr);
}
