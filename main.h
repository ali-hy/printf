#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * conversion_data - data necessary to make a conversion
 * @flag_comb: number that indicates used flags
 * @min_width: minimum length of result string
 * @precision: precision of integer result
 * @len_mod: variable size modifier
 * @conversion_code: character used as conversion specifier
 */
struct conversion_data
{
	int flag_comb;
	int min_width;
	int precision;
	char *len_mod;
	char conversion_code;
};

typedef struct conversion_data conversion_data;

conversion_data *get_conversion_data(char *c);

/* STRING UTILS */
int len(char *s);
char *copy(char *s);
char *concat(char *s1, char *s2);

char *ltos(long l, int base, int precision);
char *ultos(unsigned long l, int base, int precision);
char *dtos(double f, int precision);

int is_digit(char c);
int stoi(char *s);

/* FLAGS */
enum flags
{
	F_ALT = 1,
	F_ZERO = 2,
	F_LEFT = 4,
	F_POS_PADDING = 8,
	F_SIGN = 16
};

/**
 * flag_t - type for flags
 */
typedef enum flags flag_t;

int is_flag_active(conversion_data *c_data, flag_t flag);
void activate_flag(conversion_data *c_data, flag_t flag);
void apply_concat_flags(conversion_data *c_data, char *current);

/* FIELD WIDTH */
char *apply_width(conversion_data *c_data, char *s);

/* LENGTH MODIFIERS */
int get_conversion_base(char *len_mod);

/* CONVERT */
conversion_data *new_conversion();
char *convert_char(conversion_data *c_data, va_list l);
char *convert_str(conversion_data *c_data, va_list l);
char *percentage();

char *convert_bin(conversion_data *c_data, va_list l);
char *convert_dec(conversion_data *c_data, va_list l);
char *convert_usigned(conversion_data *c_data, va_list l);
char *convert_oct(conversion_data *c_data, va_list l);
char *convert_hex(conversion_data *c_data, va_list l);
char *apply_sign(conversion_data *c_data, char *converted_num,
		int is_negative);

/* PRINT */
int _putchar(unsigned char c);
int _putstr(char *s);

char *translate_conversion(conversion_data *c_data, va_list l);
int print_conversion(conversion_data *c_data, va_list l);

int buffer_push(char *buffer, int c);
int flush_buffer(char *buffer);

int _printf(const char *format, ...);

#endif /* MAIN_H */
