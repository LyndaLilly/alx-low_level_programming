#include "search_algos.h"

/**
 * interpolation_search - this is interpolation search 
 * @array: this is the array
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t yut, abx, tye;
	double res;

	if (array == NULL)
		return (-1);

	abx = 0;
	tye = size - 1;

	while (size)
	{
		res = (double)(tye - abx) / (array[tye] - array[abx]) * (value - array[abx]);
		yut = (size_t)(abx + res);
		printf("Value checked array[%d]", (int)yut);

		if (yut >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[yut]);
		}

		if (array[yut] == value)
			return ((int)yut);

		if (array[yut] < value)
			abx = yut + 1;
		else
			tye = yut - 1;

		if (abx == tye)
			break;
	}

	return (-1);
}
