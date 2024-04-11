#include "search_algos.h"
#include <math.h>

/**
 * jump_search - this is the jump search
 * @array: this is the array
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
int jump_search(int *array, size_t size, int value)
{
	int ptr, abx, tye, yut;

	if (array == NULL || size == 0)
		return (-1);

	abx = (int)sqrt((double)size);
	tye = 0;
	yut = ptr = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", ptr, array[ptr]);

		if (array[ptr] == value)
			return (ptr);
		tye++;
		yut = ptr;
		ptr = tye * abx;
	} while (ptr < (int)size && array[ptr] < value);

	printf("Value found between indexes [%d] and [%d]\n", yut, ptr);

	for (; yut <= ptr && yut < (int)size; yut++)
	{
		printf("Value checked array[%d] = [%d]\n", yut, array[yut]);
		if (array[yut] == value)
			return (yut);
	}

	return (-1);
}
