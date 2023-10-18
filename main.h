#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struc format - compile with the conversion specifiers for printf
 * @id: type char pointer of the spcifier
 * @f: pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
}convert_match;


int _putchar(char c);
nt ourprint_int(va_list arguments, char *buf, unsigned int ibuf);
int ourprint_dec(va_list args);
int print_bin(va_list arguments, char *buf, unsigned int ibuf);
unsigned int our_buf(char *buf, char c, unsigned int ibufp);
int _printf(const char *format, ...);
int print_chr(va_list args, char *buf, unsigned int ibuf);
int ourprint_func(const char *s, int index);
int print_string(va_list arguments, char *buf, unsigned int ibuf);
int print_perc(va_list a __attribute__((unused)), char *buf, unsigned int i);


#endif
