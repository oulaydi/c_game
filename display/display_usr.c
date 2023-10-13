#include "main.h"

/**
 * display_usr - prints a string and values of
 * non-printed chars
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int display_usr(va_list args, char *buf, unsigned int ibuf)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(args, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ibuf = grip_buf(buf, '\\', ibuf);
			ibuf = grip_buf(buf, 'x', ibuf);
			op = str[i];
			binary = load_binary_array(binary, op, 0, 32);
			hexadecimal = load_hex_array(binary, hexadecimal, 1, 8);
			ibuf = grip_buf(buf, hexadecimal[6], ibuf);
			ibuf = grip_buf(buf, hexadecimal[7], ibuf);
			sum += 3;
		}
		else
			ibuf = grip_buf(buf, str[i], ibuf);
	}
	free(binary);
	free(hexadecimal);
	return (i + sum);
}
