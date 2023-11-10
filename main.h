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

/* UTILS */
int len(char *s);
char *concat(char *s1, char *s2);

char *shtos(int sh, int base, int precision);
char *itos(int i, int base, int precision);
char *ltos(long l, int base, int precision);
char *dtos(double f, int precision);

int stoi(char *s);

/* FLAGS */
enum flags
{
	alt = 1,
	zero = 2,
	left = 4,
	pos_padding = 8,
	sign = 16
};

/**
 * flag_t - type for flags
 */
typedef enum flags flag_t;

int has_flag (int flag_comb, flag_t flag);
void apply_prefix_flags (int flag_comb, char conversion_code, char *current);

/* FIELD WIDTH */
char *apply_width(conversion_data *c_data, char *s);

/* LENGTH MODIFIERS */
int get_conversion_base(char *len_mod);

/* CONVERT */
conversion_data *new_conversion();
char *convert_char(conversion_data *c_data, va_list l);
char *convert_str(conversion_data *c_data, va_list l);
char *percentage();

/* PRINT */
int _putchar(char c);
int _putstr(char *s);

char *translate_conversion(conversion_data *c_data, va_list l);
int print_conversion(conversion_data *c_data, va_list l);

int buffer_push(char *buffer, int c);
int flush_buffer(char *buffer);

int _printf(const char *format, ...);

#endif /* MAIN_H */
