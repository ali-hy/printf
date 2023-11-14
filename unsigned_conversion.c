#include "main.h"

/**
 * get_mask - gets binary mask for different num sizes
 * @c_data: conversion data
 * Return: mask
*/
unsigned long get_mask(conv_data *c_data)
{
	unsigned long mask = ULONG_MAX;
	
	if (c_data->len_mod == NULL)
		mask = UINT_MAX;
	else if (*(c_data->len_mod) == 'h')
		mask = USHRT_MAX;
	
	printf("mask: %d\n", mask);

	return (mask);
}

/**
 * convert_uns - converts unsigned short/int/long to decimal string
 * @c_data: conversion data
 * @l: args list
 * Return: string that represents unsigned short/int/long in decimal system
 */
char *convert_uns(conv_data *c_data, va_list l)
{
	unsigned long mask = get_mask(c_data);
	unsigned long num = capture_num(c_data, l) & mask;

	if (c_data == NULL)
		return (NULL);

	return (ultos(num, 10, c_data->precision));
}

/**
 * convert_oct - converts short/int/long to octal string
 * @c_data: conversion data
 * @l: args list
 * Return: string that represents short/int/long in octal system
 */
char *convert_oct(conv_data *c_data, va_list l)
{
	char *temp, *res;
	unsigned long mask = get_mask(c_data);
	unsigned long num = capture_num(c_data, l) & mask;

	if (c_data == NULL)
		return (NULL);

	temp = ultos(num, 8, c_data->precision);
	res = temp;
	if (flag_is_active(c_data, F_ALT))
		if (temp[0] != '0')
		{
			res = concat("0", temp);
			free(temp);
		}
	return (res);
}

/**
 * convert_hex - converts short/int/long to hexadecimal string
 * @c_data: conversion data
 * @l: args list
 * Return: string that represents short/int/long in hexadecimal system
 */
char *convert_hex(conv_data *c_data, va_list l)
{
	char *temp, *res;
	unsigned long mask = get_mask(c_data);
	unsigned long num = capture_num(c_data, l) & mask;

	if (c_data == NULL)
		return (NULL);

	temp = ultos(num, 16, c_data->precision);
	res = temp;
	if (flag_is_active(c_data, F_ALT))
		if (num != 0)
		{
			res = concat("0x", temp);
			free(temp);
		}
	return (res);
}

/**
 * convert_HEX - converts short/int/long to hexadecimal string (uppercase)
 * @c_data: conversion_data
 * @l: args list
 * Return: string that represents short/int/long in hexadecimal system
 * (uppercase)
 */
char *convert_HEX(conv_data *c_data, va_list l)
{
	char *temp, *res;
	unsigned long mask = get_mask(c_data);
	unsigned long num = capture_num(c_data, l) & mask;


	if (c_data == NULL)
		return (NULL);

	temp = ultos(num, 16, c_data->precision);
	to_upper(temp);
	res = temp;
	if (flag_is_active(c_data, F_ALT))
		if (num != 0)
		{
			res = concat("0X", temp);
			free(temp);
		}
	return (res);
}
