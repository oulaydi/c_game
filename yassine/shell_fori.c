#include "shell.h"

/**
 * not_cmtr - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *not_cmtr(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = _realc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_fori - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_fori(all_data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = play_line(&i_eof);
		if (i_eof != -1)
		{
			input = not_cmtr(input);
			if (input == NULL)
				continue;

			if (verify_stx_err(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_str(input, datash);
			loop = qsem_cmd(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
