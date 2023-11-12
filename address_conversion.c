#include "main.h"

/**
 * convert_address - convert an address to hexadecimal
 * @a: address
 * Return: string of address written in hexadecimal
 */
char *convert_address(conversion_data *c_data, va_list l)
{
	unsigned long num = va_arg(l, long);

	UNUSED(c_data);

	if (num > 0)
		return (concat("0x", ultos(num, 16, 0)));
	else
		return (copy("(nil)"));
}
