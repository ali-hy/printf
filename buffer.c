#include "main.h"

/**
 * buffer_push_char - push a char to the printf buffer
 * @buffer: buffer
 * @i: index to push to
 * @c: character to push
 * Return: number of bytes printed is buffer is flushed after pushing
 */
int buffer_push_char(char *buffer, int *i, char c)
{
	buffer[*i] = c;
	(*i)++;

	if ((*i) >= BUFFER_SIZE)
		return (flush_buffer(buffer, i));

	return (0);
}

/**
 * buffer_push - push a string to the printf buffer
 * @buffer: buffer
 * @i: index to start pushing to
 * @s: string to push to buffer
 * Return: number if bytes printed if buffer is flushed during pushing
 */
int buffer_push(char *buffer, int *i, const char *s, int min)
{
	int j = 0, res = 0;


	while (s[j] != '\0')
	{
		res += buffer_push_char(buffer, i, s[j]);
		j++;
	}
	
	while (j < min)
	{
		res += buffer_push_char(buffer, i, s[j]);
		j++;
	}

	return (res);
}

/**
 * buffer_push_conversion - push conversion translation to buffer
 * @buffer: buffer
 * @i: index to start pushing from
 * @c_data: conversion data
 * @l: args_list
 * Return: number of bytes printed if buffer is flushed during pushing
 */
int buffer_push_conversion(char *buffer, int *i, conversion_data *c_data,
		va_list l)
{
	char *s = translate_conversion(c_data, l);
	int res;

	if (s == NULL)
		return (0);

	if (c_data->conversion_code == 'c')
		res = buffer_push(buffer, i, s, 1);
	else
		res = buffer_push(buffer, i, s, 0);

	if (c_data->conversion_code != '%')
		free(s);

	return (res);
}

/**
 * flush_buffer - flush buffer to std_out
 * @buffer: buffer
 * @length:	length written to in buffer
 * Return: number of bytes flushed
 */
int flush_buffer(const char *buffer, int *length)
{
	int res = write(1, buffer, *length);

	*length = 0;
	return (res);
}
