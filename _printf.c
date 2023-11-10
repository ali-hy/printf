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

	return (_putstr(s));
}

/**
 * _printf - prints data to stdout depending on format and list of args
 * @format: string dicatating format of output
 * @...: list of args, to use in format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, convert = 0;
	conversion_data *c_data = new_conversion();
	int res = 0;
	va_list l;

	va_start(l, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		/* printf("\ni = %d\n", i); */
		if (convert)
		{
			c_data->conversion_code = format[i];
			res += print_conversion(c_data, l);
			convert = 0;
		}
		else if (format[i] == '%')
		{
			convert = 1;
			continue;
		}
		else
		{
			res += _putchar(format[i]);
		}
	}
	va_end(l);

	return (res);
}
