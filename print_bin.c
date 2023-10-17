#include "main.h"

/**
 * ourprintf_bin - prints a binary number.
 * @val: arguments.
 * Return: 1.
 */
int ourprintf_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int j;

	for (i = 0; i < 32; i++)
	{
		j = ((a << (31 - i)) & num);
		if (j >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = j >> (31 - i);
			_putchar(b + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}

