#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int _putchar(char c);
int ourprint_int(va_list args);
int ourprint_dec(va_list args);
int ourprintf_bin(va_list val);
unsigned int our_buf(char *buf, char c, unsigned int ibufp);
#endif
