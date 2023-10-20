#include "main.h"

/**
 * print_hex - print hex num
 * @p: pointer
 * @params: struct
 * Return: printed
 */
int print_hex(va_list p, params_t *params)
{
	unsigned long l;
	int h = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(p, unsigned int);
	else
		l = (unsigned int)va_arg(p, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (h += print_number(str, params));
}

/**
 * print_HEX - print uppercase hex
 * @p: pointer
 * @params: struct
 * Return: printed
 */
int print_HEX(va_list p, params_t *params)
{
	unsigned long l;
	int h = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(p, unsigned int);
	else
		l = (unsigned int)va_arg(p, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (h += print_number(str, params));
}
/**
 * print_binary - print binary number
 * @p: pointer
 * @params: struct
 * Return: bytes printed
 */
int print_binary(va_list p, params_t *params)
{
	unsigned int n = va_arg(p, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int h = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (h += print_number(str, params));
}

/**
 * print_octal - print an octal numbers
 * @p: pointer to argument
 * @params: struct
 *
 * Return: printed
 */
int print_octal(va_list p, params_t *params)
{
	unsigned long l;
	char *str;
	int h = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(p, unsigned int);
	else
		l = (unsigned int)va_arg(p, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (h += print_number(str, params));
}
