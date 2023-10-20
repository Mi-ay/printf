#include "main.h"

/**
 * convert - converter
 * @num: number
 * @base: base
 * @flags: flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *digits;
	static char buffer[50];
	char sign = 0;
	char *result;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	digits = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	result = &buffer[49];
	*result = '\0';

	do {
		*--result = digits[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--result = sign;
	return (result);
}

/**
 * print_unsigned - unsigned numbers
 * @p: pointer
 * @params: the parameters struct
 *
 * Return: data printed
 */
int print_unsigned(va_list p, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(p, unsigned int);
	else
		l = (unsigned int)va_arg(p, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - shows address
 * @p: pointer
 * @params: the parameters struct
 *
 * Return: data printed
 */
int print_address(va_list p, params_t *params)
{
	unsigned long int n = va_arg(p, unsigned long int);
	char *new_addr;

	if (!n)
		return (_puts("(nil)"));

	new_addr = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--new_addr = 'x';
	*--new_addr = '0';
	return (print_number(new_addr, params));
}
