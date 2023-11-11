#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * main - entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	_printf("This is the smallest number of them all: %d\n", INT_MIN);

	for(i = -100; i < 100; i++)
	{
		_printf("This is a number: %i\n", i);
	}

	_printf("This is the largest number of them all: %d\n", INT_MAX);
	return (0);
}
