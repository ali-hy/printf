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

	UNUSED(c_data);

	buffer_push_char(c);

	return ("");
}

/**
 * convert_str - modify string with conversion data and return string
 * @c_data: conversion data
 * @l: args list
 * Return: modified string
 */
char *convert_str(conversion_data *c_data, va_list l)
{
	char *s = va_arg(l, char *);

	UNUSED(c_data);

	if (s == NULL)
		return ("(null)");

	return (s);
}

/**
 * percentage - return "%"
 * Return: "%"
 */
char *percentage()
{
	return ("%");
}

