#include "main.h"

/**
 * _puts - prints a string to st output
 * @str: string to be printed
 *
 * Return:(str-a)
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to standard output
 * @c:  character to be print
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(int c)
{
	static int d;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || d >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, d);
		d = 0;
	}
	if (c != BUF_FLUSH)
		buf[d++] = c;
	return (1);
}
