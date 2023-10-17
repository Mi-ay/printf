#include "holberton.h"

/**
 * our_buf - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @ibufp: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int our_buf(char *buf, char c, unsigned int ibufp)
{
	if (ibufp == 1024)
	{
		print_buf(buf, ibufp);
		ibufp = 0;
	}
	buf[ibufp] = c;
	ibufp++;
	return (ibufp);
}
