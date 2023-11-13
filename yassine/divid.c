#include "shell.h"

/**
 * swap_to_char - swaps | and & for non-printed chars
 *
 * @input: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *swap_to_char(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * instert_sepa - add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @input: input string
 * Return: no return
 */
void instert_sepa(sepa_list **head_s, line_list_s **head_l, char *input)
{
	int i;
	char *line;

	input = swap_to_char(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_sepa_to_end(head_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			add_sepa_to_end(head_s, input[i]);
			i++;
		}
	}

	line = _str_tok(input, ";|&");
	do {
		line = swap_to_char(line, 1);
		add_line_to_end(head_l, line);
		line = _str_tok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * _next - go to the next command line stored
 *
 * @list_s: separator list
 * @list_l: command line list
 * @datash: data structure
 * Return: no return
 */
void _next(sepa_list **list_s, line_list_s **list_l, all_data_shell *datash)
{
	int loop_sep;
	sepa_list *ls_s;
	line_list_s *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * qsem_cmd - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @datash: data structure
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */
int qsem_cmd(all_data_shell *datash, char *input)
{

	sepa_list *head_s, *list_s;
	line_list_s *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	instert_sepa(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = qsem_line(datash->input);
		loop = exe_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sepa_list(&head_s);
	free_line_list_s(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * qsem_line - tokenizes the input string
 *
 * @input: input string.
 * Return: string splitted.
 */
char **qsem_line(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFFER_SIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation err\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _str_tok(input, TOKEN_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFFER_SIZE;
			tokens = _realc_dp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation err\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _str_tok(NULL, TOKEN_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
