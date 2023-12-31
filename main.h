#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag for unsigned value
 *
 * @plus_flag: set if plus_flag specified
 * @space_flag: set if hashtag_flag specified
 * @hashtag_flag: set if _flag specified
 * @zero_flag: set if _flag specified
 * @minus_flag: set if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: set if h_modifier is specified
 * @l_modifier: set if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* version of _put.c module */
int _puts(char *str);
int _putchar(int c);

/*version of  print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_Speci(va_list ap, params_t *params);

/* version of number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* version of specifier.c module */
int (*our_specifier(char *s))(va_list ap, params_t *params);
int our_print_func(char *s, va_list ap, params_t *params);
int our_flag(char *s, params_t *params);
int our_modifier(char *s, params_t *params);
char *our_width(char *s, params_t *params, va_list ap);

/* version of convert_number.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* version of simple_printers.c module */
int print_add(char *start, char *stop, char *except);
int print_strev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* version of print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* version of params.c module */
void init_params(params_t *params, va_list ap);

/* version of string_fields.c modoule */
char *our_precision(char *p, params_t *params, va_list ap);

/* version of _prinf.c module */
int _printf(const char *format, ...);

#endif /*_MAIN_H_*/
