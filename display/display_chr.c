#include "main.h"
#include <stdio.h>
/**
 * display_chr - writes the character c to stdout
 * @args: input char
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1.
 */
int display_chr(va_list args, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(args, int);
	grip_buf(buf, c, ibuf);

	return (1);
}
