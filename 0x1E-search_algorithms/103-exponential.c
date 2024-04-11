#include "search_algos.h"

/**
  * _binary_search - this is the binary search 
  * @array: this is the array to search from
  * @left: this is the left search
  * @right: this is the right search
  * @value: this is the value
  * Return: Always EXIT_SUCCESS
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mt;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (mt = left; mt < right; mt++)
			printf("%d, ", array[mt]);
		printf("%d\n", array[mt]);

		mt = left + (right - left) / 2;
		if (array[mt] == value)
			return (mt);
		if (array[mt] > value)
			right = mt - 1;
		else
			left = mt + 1;
	}

	return (-1);
}

/**
  * exponential_search - this is the exponential search
  * @array: this is the array
  * @size: this is the size
  * @value: this is the value
  * Return: Always EXIT_SUCCESS
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t mt = 0, hx;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (mt = 1; mt < size && array[mt] <= value; mt = mt * 2)
			printf("Value checked array[%ld] = [%d]\n", mt, array[mt]);
	}

	hx = mt < size ? mt : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", mt / 2, hx);
	return (_binary_search(array, mt / 2, hx, value));
}
