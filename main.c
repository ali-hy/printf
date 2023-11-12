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
	char buffer[BUFFER_SIZE];
	int *buffer_i = malloc(sizeof(int));

	buffer_push(buffer, buffer_i, "I DON'T UNDERSTAND WHY YOU'RE NOT WORKING.\n", 0);
	flush_buffer(buffer, buffer_i);
	return (0);
}
