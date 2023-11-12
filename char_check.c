#include "main.h"

/**
 * is_digit - check if char is a digit
 * @c: char
 * Return: 1 if digit, 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}


/**
 * is_printable - check if char is printable for S specifier
 * @c: char
 * Return: 1 if printable, 0 if not
 */
int is_printable(char c)
{
	if (c < 32 || c >= 127)
		return (0);

	return (1);
}
