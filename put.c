#include "main.h"

/**
 * _putchar - print one char
 * @c: char to print
 * Return: 1 if char printed, -1 on error
 */
int _putchar(unsigned char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - print a string
 * @s: string to print
 * Return: len of printed string, -1 on error
 */
int _putstr(char *s)
{
	return (write(1, s, len(s)));
}
