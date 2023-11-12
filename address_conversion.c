#include "main.h"

/**
 * convert_address - convert an address to hexadecimal
 * @c_data: conversion data
 * @l: arg list
 * Return: string of address written in hexadecimal
 */
char *convert_address(conversion_data *c_data, va_list l)
{
	unsigned long num = va_arg(l, long);
	char *res, *converted_num;

	converted_num = ultos(num, 16, 0);
	res = concat("0x", converted_num);

	free(converted_num);

	UNUSED(c_data);

	if (num > 0)
		return (res);
	else
		return (copy("(nil)"));
}
