#include "main.h"

/**
 * ltos - convert long to string
 * @l: long integer
 * @base: number system base
 * @precision: min num of digits
 * Return: string that represents the long
 */
char *ltos(long l, int base, int precision)
{
	if (l > 0)
	{
		return (ultos((unsigned long) l, base, precision));
	}

	return (ultos((unsigned long) -l, base, precision));
}

/**
 * ultos - convert unsigned long to string
 * @ul: unsigned long integer
 * @base: number system base
 * @precision: min num of digits
 * Return: string that represents the unsigned long
 */
char *ultos(unsigned long ul, int base, int precision)
{
	unsigned long curr = ul;
	int i,  length = 0;
	char *map = "0123456789abcdef";
	char *res;

	while (curr != 0)
	{
		curr /= base;
		length++;
	}

	if (precision > length)
		length = precision;
	if (length == 0)
		length = 1;

	res = malloc(length + 1);
	if (res == NULL)
		return (NULL);

	res[length] = '\0';
	curr = ul;
	for (i = length - 1; i >= 0; i--)
	{
		res[i] = map[curr % base];
		curr /= base;
	}

	return (res);
}

/**
 * apply_sign - returns number with correct sign depending on flag and value
 * @c_data: pointer to conversion_data
 * @converted_num: string representing number
 * @is_negative: 0 if the number is negative, 1 if the number isn't
 * Return: new string representing the number, but with the correct sign
 */
char *apply_sign(conversion_data *c_data, char *converted_num, int is_negative)
{
	char *sign = "", *res;

	if (is_negative)
		sign = "-";
	else if (is_flag_active(c_data, F_POS_PADDING))
		sign = " ";
	else if (is_flag_active(c_data, F_SIGN))
		sign = "+";

	res = concat(sign, converted_num);
	free(converted_num);
	return (res);
}

/**
 * convert_bin - convert short/int/long to binary string
 * @c_data: pointer to conversion_data
 * @l: argument list
 * Return: string representing argument in binary number system
 */
char *convert_bin(conversion_data *c_data, va_list l)
{
	unsigned int num = va_arg(l, unsigned int);
	char *res;

	if (c_data == NULL)
	{
		res = malloc(1);
		res[0] = '\0';
	}
	else
	{
		res = ultos(num, 2, 0);
	}

	return (res);
}

/**
 * convert_dec - convert short/int/long to decimal string
 * @c_data: pointer to conversion_data
 * @l: argument list
 * Return: string representing argument in decimal number system
 */
char *convert_dec(conversion_data *c_data, va_list l)
{
	long num = va_arg(l, int);
	char *res = apply_sign(c_data, ltos(num, 10, 0), num < 0);

	return (res);
}
