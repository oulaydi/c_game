#include "main.h"

/**
 * display_buf - prints buffer
 * @buf: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int display_buf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}
