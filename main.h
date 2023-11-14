#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) ((void)(x))

/**
 * struct conversion_data - data necessary to make a conversion
 * @flag_comb: number that indicates used flags
 * @min_width: minimum length of result string
 * @precision: precision of integer result
 * @len_mod: variable size modifier
 * @code: character used as conversion specifier
 */
struct conv_data
{
	int flag_comb;
	int min_width;
	int precision;
	const char *len_mod;
	char code;
};

typedef struct conv_data conv_data;

conv_data get_conversion_data(const char **c);

/* STRING UTILS */
int len(const char *s);
char *copy(const char *s);
char *concat(const char *s1, const char *s2);
char *to_upper(char *s1);

char *ltos(long l, int base, int precision);
char *ultos(unsigned long l, int base, int precision);
char *dtos(double f, int precision);
unsigned long get_mask(conv_data *c_data);

int is_digit(char c);
int is_flag(char c);
int is_len_mod(char c);
int is_nonprintable(char c);
int is_number_code(char c);
int stoi(const char **s);

/* FLAGS */
enum flags
{
	F_ALT = 1,
	F_ZERO = 2,
	F_LEFT = 4,
	F_SPACE = 8,
	F_SIGN = 16
};

/**
 * flag_t - type for flags
 */
typedef enum flags flag_t;

int flag_is_active(conv_data *c_data, flag_t flag);
void activate_flag(conv_data *c_data, flag_t flag);

/* TODO: Impliment funcitons */
void apply_concat_flags(conv_data *c_data, const char *current);
/* */

/* FIELD WIDTH */
char *apply_width(conv_data *c_data, char *s);
char *blank(conv_data *c_data, int n);

/* LENGTH MODIFIERS */
int capture_int(va_list l);
unsigned int capture_uint(va_list l);
long capture_long(va_list l);
unsigned long capture_num(conv_data *c_data, va_list l);

/* CONVERT */
conv_data *new_conversion();
void reset_conversion(conv_data *c_data);
char *test_conversion(conv_data *c_data, ...);
char *(*pick_convertor_func(conv_data *c_data))(conv_data *, va_list);
char *convert_char(conv_data *c_data, va_list l);
char *convert_str(conv_data *c_data, va_list l);
char *convert_printable(conv_data *data, va_list l);
char *percentage();

char *convert_bin(conv_data *c_data, va_list l);
char *convert_dec(conv_data *c_data, va_list l);
char *convert_uns(conv_data *c_data, va_list l);
char *convert_oct(conv_data *c_data, va_list l);
char *convert_hex(conv_data *c_data, va_list l);
char *convert_HEX(conv_data *c_data, va_list l);
char *convert_address(conv_data *c_data, va_list l);
char *apply_sign(conv_data *c_data, char *converted_num,
				 int is_negative);

/* PRINT */
int _putchar(unsigned char c);
int _putstr(const char *s);

char *translate_conversion(conv_data *c_data, va_list l);
int print_conversion(conv_data *c_data, va_list l);

int buffer_push(const char *s, int min);
int buffer_push_char(int s);
int buffer_push_conversion(conv_data *c_data,
						   va_list l);
int flush_buffer(char *buffer, int *i);
int _printf(const char *format, ...);

#endif /* MAIN_H */
