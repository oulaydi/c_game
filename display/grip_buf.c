#include "main.h"

/**
 * grip_buf - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @ibuf: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int grip_buf(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		display_buf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}
