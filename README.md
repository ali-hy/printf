# Printf

This is a custom printf function in C, part of the ALX SWE program.

Here is a list of the functions allowed from the standard library:
- `write (man 2 write)`
- `malloc (man 3 malloc)`
- `free (man 3 free)`
- `va_start (man 3 va_start)`
- `va_end (man 3 va_end)`
- `va_copy (man 3 va_copy)`
- `va_arg (man 3 va_arg)`

## Mandatory functionality

Prototype: `int _printf(const char *format, ...);`

Returns: the number of characters printed (excluding the null byte used to end
output to strings)

write output to stdout, the standard output stream

format is a character string. The format string is composed of zero or more
directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
- c
- s
- %
- d
- i

**Note:** flags don't have to be handled
