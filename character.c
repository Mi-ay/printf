#include "main.h"

/**
 * print_char - prints character
 * @p:  pointer
 * @params: parameters struct
 *
 * Return: number of characters printed
 */
int print_char(va_list p, params_t *params)
{
	char space_char = ' ';
	unsigned int pad = 1, add = 0, ch = va_arg(p, int);

	if (params->minus_flag)
		add += _putchar(ch);
	while (pad++ < params->width)
		add += _putchar(space_char);
	if (!params->minus_flag)
		add += _putchar(ch);
	return (add);
}

/**
 * print_int - prints integer
 * @p: pointer
 * @params: parameters struct
 *
 * Return: numberof characters printed
 */
int print_int(va_list p, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(p, long);
	else if (params->h_modifier)
		l = (short int)va_arg(p, int);
	else
		l = (int)va_arg(p, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @p:  pointer
 * @params: parameters struct
 *
 * Return: number of characters printed
 */
int print_string(va_list p, params_t *params)
{
	char *str = va_arg(p, char *), space_char = ' ';
	unsigned int pad = 0, add = 0, r = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (r = 0; r < pad; r++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	while (j++ < params->width)
		add += _putchar(space_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (r = 0; r < pad; r++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	return (add);
}

/**
 * print_percent - prints
 * @p: pointer
 * @params: struct
 *
 * Return: number of characters printed
 */
int print_percent(va_list p, params_t *params)
{
	(void)p;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - format specifier
 * @p: pointer
 * @params: parameters
 *
 * Return: number of characters printed
 */
int print_S(va_list p, params_t *params)
{
	char *str = va_arg(p, char *);
	char *hex;
	int add = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				add += _putchar('0');
			add += _puts(hex);
		}
		else
		{
			add += _putchar(*str);
		}
	}
	return (add);
}
