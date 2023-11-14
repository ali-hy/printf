#include "main.h"

/**
 * convert_printable - return a string where non-printable characters are
 * replaced with \x
 * @c_data: conversion data
 * @l: args list
 * Return: string where non-printable characters are replaced with \x
 */
char *convert_printable(conv_data *c_data, va_list l)
{
	int length = 0, i = 0, j = 0;
	const char *s = va_arg(l, const char *);
	char *res, *hex;

	UNUSED(c_data);

	if (s == NULL)
		return ("(null)");

	while (s[i] != '\0')
	{
		i++;
		length++;
		if (is_nonprintable(s[i]))
			length += 3;
	}

	res = malloc(length + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < length; i++, j++)
	{
		if (!is_nonprintable(s[j]))
		{
			res[i] = s[j];
			continue;
		}

		res[i++] = '\\';
		res[i++] = 'x';

		hex = ultos(s[j], 16, 2);
		to_upper(hex);
		res[i++] = hex[0];
		res[i] = hex[1];
		free(hex);
	}

	return (res);
}
