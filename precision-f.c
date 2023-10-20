#include "main.h"

/**
 * our_precision - handle precision string
 * @s: string
 * @params: the parameters struct
 * @p: pointer
 * Return: new pointer
*/

char *our_precision(char *s, params_t *params, va_list p)
{
	int preci_value = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		preci_value = va_arg(p, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			preci_value = preci_value * 10 + (*s++ - '0');
	}
	params->precision = preci_value;
	return (s);
}
