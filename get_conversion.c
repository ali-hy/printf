#include "main.h"

/**
 * get_conversion_data - extract conversion data from string
 * @s: pointer to starting point of extraction
 * Return: conversion data
*/
conv_data get_conversion_data(const char **s)
{
	conv_data c_data;
	flag_t cur_flag = is_flag(**s);

	reset_conversion(&c_data);
	while (cur_flag)
	{
		activate_flag(&c_data, cur_flag);
		(*s)++;
		cur_flag = is_flag(**s);
	}
	c_data.min_width = stoi(s);
	if (**s == '.')
	{
		(*s)++;
		c_data.precision = stoi(s);
	}
	if (is_len_mod(**s))
	{
		c_data.len_mod = *s;
		(*s)++;
	}
	c_data.code = **s;

	return (c_data);
}
