#include "main.h"

/**
 * convert_uns - converts unsigned short/int/long to decimal string
 * @c_data: conversion data
 * @l: args list
 * Return: string that represents unsigned short/int/long in decimal system
 */
char *convert_uns(conversion_data *c_data, va_list l)
{
	unsigned long num = capture_num(c_data, l);

	if (c_data == NULL)
		return (NULL);

	return (ultos(num, 10, 0));
}

/**
 * convert_oct - converts short/int/long to octal string
 * @c_data: conversion data
 * @l: args list
 * Return: string that represents short/int/long in octal system
 */
char *convert_oct(conversion_data *c_data, va_list l)
{
	char *temp, *res;
	unsigned long num = capture_num(c_data, l);

	if (c_data == NULL)
		return (NULL);

	temp = ultos(num, 8, 0);
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
char *convert_hex(conversion_data *c_data, va_list l)
{
	char *temp, *res;
	unsigned long num = capture_num(c_data, l);

	if (c_data == NULL)
		return (NULL);

	temp = ultos(num, 16, 0);
	res = temp;
	if (flag_is_active(c_data, F_ALT))
		if (num != 0)
		{
			res = concat("0x", temp);
			free (temp);
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
char *convert_HEX(conversion_data *c_data, va_list l)
{
	char *temp, *res;
	unsigned long num = capture_num(c_data, l);

	if (c_data == NULL)
		return (NULL);

	temp = ultos(num, 16, 0);	
	to_upper(temp);
	res = temp;
	if (flag_is_active(c_data, F_ALT))
		if (num != 0)
		{
			res = concat("0X", temp);
			free (temp);
		}
	return (res);
}
