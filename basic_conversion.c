#include "main.h"

/**
 * convert_char - makes conversion data and char into string
 * @c_data: conversion data
 * @l: args list
 * Return: resulting string
 */
char *convert_char(conversion_data *c_data, va_list l)
{
	unsigned char c = va_arg(l, int);
	char *res = malloc(2 * sizeof(char));

	if (res == NULL || c_data == NULL)
		return (NULL);

	res[0] = c;
	res[1] = '\0';

	return (res);
}

/**
 * convert_str - modify string with conversion data and return string
 * @c_data: conversion data
 * @l: args list
 * Return: modified string
 */
char *convert_str(conversion_data *c_data, va_list l)
{
	const char *s = va_arg(l, const char *);
	char *res = copy(s);

	UNUSED(c_data);

	if (res == NULL)
		return (copy("(null)"));

	return (res);
}

/**
 * percentage - return "%"
 * Return: "%"
 */
char *percentage()
{
	return ("%");
}


