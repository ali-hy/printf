#include "main.h"

/**
 * print_conversion - takes conversion data and prints next arg
 * @c_data: conversion data
 * @l: args list
 * Return: number of characters printed
 */
int print_conversion(conversion_data *c_data, va_list l)
{
	char *s = translate_conversion(c_data, l);
	int res = _putstr(s);

	if (c_data->code != '%')
		free(s);

	return (res);
}

/**
 * _printf - prints data to stdout depending on format and list of args
 * @format: string dicatating format of output
 * @...: list of args, to use in format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, convert = 0, res = 0;
	conversion_data c_data;
	va_list l;

	reset_conversion(&c_data);

	if (format == NULL)
		return (-1);

	va_start(l, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (convert)
		{
			c_data.code = format[i];
			res += buffer_push_conversion(&c_data, l);

			convert = 0;
		}
		else if (format[i] == '%')
		{
			convert = 1;
		}
		else
		{
			res += buffer_push_char(format[i]);
		}
	}
	va_end(l);

	if (convert)
		return (-1);

	res += buffer_push_char(-1);

	return (res);
}
