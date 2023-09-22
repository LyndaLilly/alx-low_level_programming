#include <stdio.h>
void printMessage(void) __attribute__ ((constructor));
/**
* printMessage - prints a sentence before the main
* function is executed
*/
void printMessage(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
