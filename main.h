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
int ourprint_int(va_list args);
int ourprint_dec(va_list args);
int ourprintf_bin(va_list val);
unsigned int our_buf(char *buf, char c, unsigned int ibufp);
int _printf(const char *format, ...);
int printf_char(va_list val);
int prints_string(va_list val);
int _strlen(char *s);
int _strlenc(const char *s);
int printf_37(void);


#endif
