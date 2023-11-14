#include "main.h"

/**
 * new_conversion - makes new conversion_data object
 * Return: new conversion_data object
 */
conversion_data *new_conversion()
{
	conversion_data *conv = malloc(sizeof(conversion_data));

	if (conv == NULL)
	{
		return (NULL);
	}

	conv->flag_comb = 0;
	conv->min_width = 0;
	conv->precision = 0;
	conv->len_mod = NULL;
	conv->conversion_code = '\0';

	return (conv);
}

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
	char *s = va_arg(l, char *);
	char *res = copy(s);

	if (!c_data)
		return (NULL);

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

/**
 * translate_conversion - turns conversion into string
 * @c_data: conversion data
 * @l: args list
 * Return: string represented by conversion
 */
char *translate_conversion(conversion_data *c_data, va_list l)
{
	char *(*convertor_func)(conversion_data *, va_list);

	char *(*convertor_funcs[256])(conversion_data *, va_list);

	int i = 0;
	char *res;

	while (i < 256)
	{
		convertor_funcs[i++] = NULL;
	}

	convertor_funcs['c'] = convert_char;
	convertor_funcs['s'] = convert_str;
	convertor_funcs['%'] = percentage;
	convertor_funcs['d'] = convert_dec;
	convertor_funcs['i'] = convert_dec;
	convertor_funcs['b'] = convert_bin;

	convertor_func = convertor_funcs[(int)c_data->conversion_code];
	if (convertor_func == NULL)
	{
		res = malloc(2);
		if (res == NULL)
		{
			return (NULL);
		}
		res[0] = c_data->conversion_code;
		res[1] = '\0';
		return (res);
	}

	return (convertor_func(c_data, l));
}
