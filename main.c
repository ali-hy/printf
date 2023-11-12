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

	i = _printf("12%c3", '\0');
	_printf("\nTHAT WAS %d CHARS LONG", i);

	return (0);
}
