#include "main.h"

/**
 * print_char - prints character
 * @p:  pointer to character
 * @params: structure of parameter
 *
 * Return: number of characters printed
 */
int print_char(va_list p, params_t *params)
{
	char space_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(p, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(space_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}
/**
 * print_int - to prints integer
 * @p: pointer to integer
 * @params: structure of parameter
 *
 * Return: number of characters printed
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}
/**
 * print_string - prints string
 * @p:  pointer to string
 * @params: parameters struct
 *
 * Return: number of characters printed
 */
int print_string(va_list p, params_t *params)
{
	char *str = va_arg(p, char *), space_char = ' ';
	unsigned int pad = 0, sum = 0, d = 0, a;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	a = pad = _strlen(str);
	if (params->precision < pad)
		a = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (d = 0; d < pad; d++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (a++ < params->width)
		sum += _putchar(space_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (d = 0; d < pad; d++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints pecentage symbol
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
 * print_Speci - format specifier
 * @p: pointer
 * @params: parameters
 *
 * Return: number of characters printed
 */
int print_Speci(va_list p, params_t *params)
{
	char *str = va_arg(p, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
