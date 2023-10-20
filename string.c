#include "main.h"

/**
 * print_add - print addresses
 * @start: start
 * @stop: stop
 * @except: except
 *
 * Return: number
 */
int print_add(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_strev - print string reverse
 * @p: string to reverse
 * @params: the parameters struct
 *
 * Return: number data printed
 */
int print_strev(va_list p, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(p, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 -  string rot13
 * @p: string
 * @params: the parameters struct
 *
 * Return: number data printed
 */
int print_rot13(va_list p, params_t *params)
{
	int r, k;
	int c_rot = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(p, char *);
	(void)params;

	r = 0;
	k = 0;
	while (a[r])
	{
		if ((a[r] >= 'A' && a[r] <= 'Z')
		    || (a[r] >= 'a' && a[r] <= 'z'))
		{
			k = a[r] - 65;
			c_rot += _putchar(arr[k]);
		}
		else
			c_rot += _putchar(a[r]);
		r++;
	}
	return (c_rot);
}
