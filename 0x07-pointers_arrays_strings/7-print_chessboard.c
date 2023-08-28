#include "main.h"

/**
 * print-chessboard - prints the chessboard
 * @a: pointer to pieces to print
 *
 * This function prints the chessboard by iterating through the 2D array
 * of characters and printing each character to the standard output.
 * Each row of the chessboard is separated by a newline character.
 *
 * @a: The 2D array representing the chessboard.
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
