#include "main.h"

/**
 * displayhunt - prints a short unsigned integer
 * @args: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int displayhunt(va_list args, char *buf, unsigned int ibuf)
{
	unsigned short int int_in, int_temp, i, div;

	int_in = va_arg(args, unsigned int);

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = grip_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i);
}
