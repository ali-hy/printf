#include "main.h"

/**
 * buffer_push_char - push a char to the printf buffer
 * @c: character to push
 * Return: number of bytes printed is buffer is flushed after pushing
 */
int buffer_push_char(int c)
{
	int res = 0;
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c < 0 || i >= BUFFER_SIZE)
	{
		res += (flush_buffer(buffer, &i));
	}

	if (c >= 0)
	{
		buffer[i] = (char)c;
		i++;
	}

	return (res);
}

/**
 * buffer_push - push a string to the printf buffer
 * @s: string to push to buffer
 * @min: min number of chars to print
 * Return: number if bytes printed if buffer is flushed during pushing
 */
int buffer_push(const char *s, int min)
{
	int j = 0, res = 0;

	while (s[j] != '\0')
	{
		res += buffer_push_char(s[j]);
		j++;
	}

	while (j < min)
	{
		res += buffer_push_char(s[j]);
		j++;
	}

	return (res);
}

/**
 * buffer_push_conversion - push conversion translation to buffer
 * @c_data: conversion data
 * @l: args_list
 * Return: number of bytes printed if buffer is flushed during pushing
 */
int buffer_push_conversion(conversion_data *c_data,
													 va_list l)
{
	char *s = translate_conversion(c_data, l);
	int res;

	if (s == NULL)
		return (0);

	res = buffer_push(s, 0);

	if (c_data->code != 'c' &&
			c_data->code != '%')
		free(s);

	return (res);
}

/**
 * flush_buffer - flush buffer to std_out
 * @buffer: buffer
 * @length:	length written to in buffer
 * Return: number of bytes flushed
 */
int flush_buffer(char *buffer, int *length)
{
	int res = write(1, buffer, *length);

	*length = 0;
	return (res);
}
