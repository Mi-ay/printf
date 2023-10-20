#include "main.h"

/**
 * _isdigit - check if a char is digit
 * @c: the character t
 *
 * Return: 1
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - the string length
 * @s: string
 *
 * Return: int
 */
int _strlen(char *s)
{
	int d = 0;

	while (*s++)
		d++;
	return (d);
}

/**
 * print_number - print number
 * @str: string
 * @params: struct
 *
 * Return: chars
 */
int print_number(char *str, params_t *params)
{
	unsigned int d = _strlen(str);
	int t = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (t)
	{
		str++;
		d--;
	}
	if (params->precision != UINT_MAX)
		while (d++ < params->precision)
			*--str = '0';
	if (t)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - number
 * @str: string
 * @params: struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int shift = 0, v, z, r = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	v = z = (!params->unsign && *str == '-');
	if (v && r < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		v = 0;
	if ((params->plus_flag && !z) ||
		(!params->plus_flag && params->space_flag && !z))
		r++;
	if (v && pad_char == '0')
		shift += _putchar('-');
	if (params->plus_flag && !z && pad_char == '0' && !params->unsign)
		shift += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !z &&
		!params->unsign && params->zero_flag)
		shift += _putchar(' ');
	while (r++ < params->width)
		shift += _putchar(pad_char);
	if (v && pad_char == ' ')
		shift += _putchar('-');
	if (params->plus_flag && !z && pad_char == ' ' && !params->unsign)
		shift += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !z &&
		!params->unsign && !params->zero_flag)
		shift += _putchar(' ');
	shift += _puts(str);
	return (shift);
}

/**
 * print_number_left_shift - number
 * @str: string
 * @params:  struct
 *
 * Return: chars
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int shift = 0, v, z, r = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	v = z = (!params->unsign && *str == '-');
	if (v && r < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		v = 0;

	if (params->plus_flag && !z && !params->unsign)
		shift += _putchar('+'), r++;
	else if (params->space_flag && !z && !params->unsign)
		shift += _putchar(' '), r++;
	shift += _puts(str);
	while (r++ < params->width)
		shift += _putchar(pad_char);
	return (shift);
}
