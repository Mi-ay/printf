#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struc format - compile with the conversion specifiers for printf
 * @ig: type char pointer of the spcifier
 * @p: pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *ig;
	int (*p)();
	convert_match;
}

int _putchar(char c);
int ourprint_int(va_list args);
int ourprint_dec(va_list args);
int ourprintf_bin(va_list val);
unsigned int our_buf(char *buf, char c, unsigned int ibufp);
int _printf(const char *format, ...);

#endif
