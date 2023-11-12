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

	if (c_data->conversion_code != '%')
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
	int i, convert = 0, res = 0, buffer_index = 0;
	conversion_data *c_data = new_conversion();
	char buffer[BUFFER_SIZE];
	va_list l;

	va_start(l, format);
	if (format != NULL)
		for (i = 0; format[i] != '\0'; i++)
		{
			if (convert)
			{
				c_data->conversion_code = format[i];
				res += buffer_push_conversion(buffer, &buffer_index, c_data, l);

				convert = 0;
			}
			else if (format[i] == '%')
			{
				convert = 1;
			}
			else
			{
				res += buffer_push_char(buffer, &buffer_index, format[i]);
			}
		}
	va_end(l);
	res = flush_buffer(buffer, &buffer_index);

	free(c_data);

	return (res);
}
