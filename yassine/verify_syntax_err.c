#include "main.h"

/**
 * iterative_char - counts the repetitions of a char
 *
 * @input: input string
 * @i: index
 * Return: repetitions
 */
int iterative_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (iterative_char(input - 1, i + 1));

	return (i);
}

/**
 * err_sepa_op - finds syntax errors
 *
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int err_sepa_op(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (err_sepa_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = iterative_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = iterative_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (err_sepa_op(input + 1, i + 1, *input));
}

/**
 * fst_char - finds index of the first char
 *
 * @input: input string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */
int fst_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * display_syntax_err - prints when a syntax error is found
 *
 * @datash: data structure
 * @input: input string
 * @i: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void display_syntax_err(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = _itoa(datash->counter);
	length = _str_len(datash->av[0]) + _str_len(counter);
	length += _str_len(msg) + _str_len(msg2) + _str_len(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_str_cpy(error, datash->av[0]);
	_str_cat(error, ": ");
	_str_cat(error, counter);
	_str_cat(error, msg2);
	_str_cat(error, msg);
	_str_cat(error, msg3);
	_str_cat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * verify_syntax_err - intermediate function to
 * find and print a syntax error
 *
 * @datash: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int verify_syntax_err(data_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = fst_char(input, &begin);
	if (f_char == -1)
	{
		display_syntax_err(datash, input, begin, 0);
		return (1);
	}

	i = err_sepa_op(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		display_syntax_err(datash, input, begin + i, 1);
		return (1);
	}

	return (0);
}
