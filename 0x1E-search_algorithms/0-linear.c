#include "search_algos.h"

/**
 * linear_search - this is the linear search algorithm
 * @array: this is the array
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	int mt;

	if (array == NULL)
		return (-1);

	for (mt = 0; mt < (int)size; mt++)
	{
		printf("Value checked array[%u] = [%d]\n", mt, array[mt]);
		if (value == array[mt])
			return (mt);
	}
	return (-1);
}
