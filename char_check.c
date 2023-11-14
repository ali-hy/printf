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
 * is_nonprintable - check if char is printable for S specifier
 * @c: char
 * Return: 1 if nonprintable, 0 if not
 */
int is_nonprintable(char c)
{
	if (c < 32 || c >= 127)
		return (1);

	return (0);
}

/**
 * is_flag - check if char is a flag
 * @c: char
 * Return: flag if c is a flag, 0 if not
 */
int is_flag(char c)
{
	switch (c)
	{
		case '#':
			return (F_ALT);
		case '0':
			return (F_ZERO);
		case '-':
			return (F_LEFT);
		case ' ':
			return (F_SPACE);
		case '+':
			return (F_SIGN);
		default:
			return (0);
	}
}

int is_len_mod(char c)
{
	return (c == 'h' || c == 'l');
}