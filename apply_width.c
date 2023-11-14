#include "main.h"

/**
 * apply_width - applys min_width of conversion data to string
 * @c_data: conversion data
 * @s: string min_width is applied to
 * Return: new string with min width specified in c_data
*/
char *apply_width(conv_data *c_data, char *s)
{
	int length = len(s);
	char *res = copy(s), *temp;

	if (length >= c_data->min_width)
		return (res);

	temp = blank(c_data, c_data->min_width - length);
	if (flag_is_active(c_data, F_LEFT))
		res = concat(s, temp);
	else
		res = concat(temp, s);
	free(temp);

	return (res);
}

/**
 * blank - creates blank string to achieve minimum width
 * @c_data: conversion data
 * @n: length of blank
 * Return: string containing blank characters
*/
char *blank(conv_data *c_data, int n)
{
	char *res = malloc(n + 1);
	char c = (flag_is_active(c_data, F_ZERO)
		&& is_number_code(c_data->code)) ? '0' : ' ';

	if (res == NULL)
		return (NULL);

	res[n] = '\0';
	while (--n >= 0)
	{
		printf("loop ongoing\n");
		res[n] = c;
	}
	return (res);
}
