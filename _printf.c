#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%i", ourprint_int}, {"%d", ourprint_dec},
	       	{"%b", ourprintf_bin}
	};

	va_list args;
	int i = 0, k, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		k = 13;
		while (k >= 0)
		{
			if (m[k].id[0] == format[i] && m[k].id[1] == format[i + 1])
			{
				len += m[k].f(args);
				i = i + 2;
				goto Here;
			}
			k--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
