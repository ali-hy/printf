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
 * translate_conversion - turns conversion into string
 * @c_data: conversion data
 * @l: args list
 * Return: string represented by conversion
 */
char *translate_conversion(conversion_data *c_data, va_list l)
{
	char *(*convertor_func)(conversion_data *, va_list);

	char *(*convertor_funcs[256])(conversion_data *, va_list);
	char *res;

	int i = 0;

	while (i < 256)
		convertor_funcs[i++] = NULL;

	convertor_funcs['c'] = convert_char; 
	convertor_funcs['s'] = convert_str;
	convertor_funcs['%'] = percentage; 
	convertor_funcs['d'] = convert_dec;
	convertor_funcs['i'] = convert_dec;
	convertor_funcs['b'] = convert_bin;
	convertor_funcs['u'] = convert_uns;
	convertor_funcs['o'] = convert_oct;
	convertor_funcs['x'] = convert_hex;
	convertor_funcs['X'] = convert_HEX;
	convertor_funcs['S'] = convert_printable;
	convertor_funcs['p'] = convert_address;

	
	convertor_func = convertor_funcs[(int)c_data->conversion_code];
	if (convertor_func == NULL)
	{
		res = malloc(3);
		if (res == NULL)
		{
			return (NULL);
		}

		res[0] = '%';
		res[1] = c_data->conversion_code;
		res[2] = '\0';
		return (res);
	}

	return (convertor_func(c_data, l));
}
