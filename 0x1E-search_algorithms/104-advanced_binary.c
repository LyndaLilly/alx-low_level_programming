#include "search_algos.h"

/**
 * rec_search - this is the rec search 
 * @array: this is the array
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
int rec_search(int *array, size_t size, int value)
{
	size_t ptr = size / 2;
	size_t mt;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (mt = 0; mt < size; mt++)
		printf("%s %d", (mt == 0) ? ":" : ",", array[mt]);

	printf("\n");

	if (ptr && size % 2 == 0)
		ptr--;

	if (value == array[ptr])
	{
		if (ptr > 0)
			return (rec_search(array, ptr + 1, value));
		return ((int)ptr);
	}

	if (value < array[ptr])
		return (rec_search(array, ptr + 1, value));

	ptr++;
	return (rec_search(array + ptr, size - ptr, value) + ptr);
}

/**
 * advanced_binary - this is the advanced binary
 * @array: this is the array
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{
	int res;

	res = rec_search(array, size, value);

	if (res >= 0 && array[res] != value)
		return (-1);

	return (res);
}
