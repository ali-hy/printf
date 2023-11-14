#include "main.h"

/**
 * capture_int - get int from arg list
 * @l: arg list
 * Return: int from arg list
*/
int capture_int(va_list l)
{
	return (va_arg(l, int));
}

/**
 * capture_long - get long from arg list
 * @l: arg list
 * Return: long from arg list
*/
long capture_long(va_list l)
{
	return (va_arg(l, long));
}

/**
 * capture_num - get corrent type of num from arg list
 * @c_data: conversion data (with length modifier)
 * @l: arg list
 * Return: correct type of num from arg list
*/
long capture_num(conv_data *c_data, va_list l)
{
	if (c_data->len_mod == NULL)
		return (capture_int(l));

	if (*(c_data->len_mod) == 'l')
		return (capture_long(l));

	if (c_data->code == 'i' || c_data->code == 'd')
		return (capture_int(l));

	return (capture_uint(l));
}

/**
 * capture_uint - get unsigned int from arg list
 * @l: arg list
 * Return: unsigned int from arg list
*/
unsigned int capture_uint(va_list l)
{
	return (va_arg(l, unsigned int));
}
