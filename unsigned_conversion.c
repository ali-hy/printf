#include "main.h"

/**
 * convert_unsigned - converts unsigned short/int/long to decimal string
 * @*c_data: conversion data
 * @l: args list
 * Reutrn: string that represents unsigned short/int/long in decimal system
 */
char *convert_unsigned(conversion_data *c_data, va_list l)
{
	unsigned long num = va_arg(l, unsigned int);
	
	if(c_data == NULL)
		return (NULL);

	return (ultos(num, 10, 0));
}

/**
 * convert_oct - converts short/int/long to octal string
 * @*c_data: conversion data
 * @l: args list
 * Return: string that represents short/int/long in octal system
 */
char *convert_oct(conversion_data *c_data, va_list l)
{
	unsigned long num = va_arg(l, unsigned int);

	if (c_data == NULL)
		return (NULL);

	return (ultos(num, 8, 0));
}

/**
 * convert_hex - converts short/int/long to hexadecimal string
 * @*c_data: conversion data
 * @l: args list
 * Return: string that represents short/int/long in hexadecimal system
 */
char *convert_hex(conversion_data *c_data, va_list l)
{
	unsigned long num = va_arg(l, unsigned int);

	if (c_data == NULL)
		return (NULL);

	return (ultos(num, 16, 0));
}

/**
 * convert_HEX - converts short/int/long to hexadecimal string (uppercase)
 * @*c_data: conversion_data
 * @l: args list
 * Return: string that represents short/int/long in hexadecimal system
 * (uppercase)
 */
char *convert_HEX(conversion_data *c_data, va_list l)
{
	unsigned long num = va_arg(l, unsigned int);

	if (c_data == NULL)
		return (NULL);

	return (to_upper(ultos(num, 16, 0)));
}
