#include "main.h"

/**
 * _printf - prints to the standard output
 * @format: format string
 * Return: number of datas printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list xy;
	char *p, *start;

	params_t params = PARAMS_INIT;

	va_start(xy, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, xy);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (our_flag(p, &params))
		{
			p++;
		}
		p = our_width(p, &params, xy);
		p = our_precision(p, &params, xy);
		if (our_modifier(p, &params))
			p++;
		if (!our_specifier(p))
			sum += print_add(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += our_print_func(p, xy, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(xy);
	return (sum);
}
