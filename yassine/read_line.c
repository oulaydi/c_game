#include "shell.h"

/**
 * play_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *play_line(int *i_eof)
{
	char *input = NULL;
	size_t BUFFER_SIZE = 0;

	*i_eof = getline(&input, &BUFFER_SIZE, stdin);

	return (input);
}
