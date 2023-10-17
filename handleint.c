#include "main.h"
/**
 * ourprint_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int ourprint_int(va_list args)
{
	int j = va_arg(args, int);
	int num, last = j % 10, digit, exp = 1;
	int  i = 1;

	j = j / 10;
	num = j;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		j = -j;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = j;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}

/**
 * ourprint_dec - prints decimal
 * @args: argument to print
 * Return: number of characters printed
 */

int ourprint_dec(va_list args)
{
	int j = va_arg(args, int);
	int num, last = j % 10, digit;
	int  j = 1;
	int exp = 1;

	j = j / 10;
	num = j;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		j = -j;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = j;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
