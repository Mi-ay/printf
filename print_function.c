#include "main.h"

/**
 * _printf - prints to the standard output
 * @format: format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int add = 0;
	va_list p;
	char *p, *start;

	params_t params = PARAMS_INIT;

	va_start(p, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, p);
		if (*p != '%')
		{
			add += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (our_flag(p, &params))
		{
			p++;
		}
		p = our_width(p, &params, p);
		p = our_precision(p, &params, p);
		if (our_modifier(p, &params))
			p++;
		if (!our_specifier(p))
			add += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			add += our_print_func(p, p, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(p);
	return (add);
}
