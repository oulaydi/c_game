#include "main.h"

/**
 * displaysint - prints int begining with space
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int displaysint(va_list args, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(args, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = grip_buf(buf, '-', ibuf);
	}
	else
	{
		int_in = int_input;
		ibuf = grip_buf(buf, ' ', ibuf);
	}
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
	return (i + 1);
}
