#include "shell.h"

/**
 * verify_enva - verifys if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void verify_enva(str_var **h, char *in, all_data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _str_len(_envr[row] + chr + 1);
				var_to_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	var_to_node(h, j, NULL, 0);
}

/**
 * verify_vars - verify if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int verify_vars(str_var **h, char *in, char *st, all_data_shell *data)
{
	int i, lst, lpd;

	lst = _str_len(st);
	lpd = _str_len(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				var_to_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				var_to_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				var_to_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				var_to_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				var_to_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				var_to_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				var_to_node(h, 0, NULL, 0);
			else
				verify_enva(h, in + i, data);
		}
	}

	return (i);
}

/**
 * change_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *change_input(str_var **head, char *input, char *new_input, int nlen)
{
	str_var *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_str - calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */
char *rep_str(char *input, all_data_shell *datash)
{
	str_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = _itoa(datash->status);
	head = NULL;

	olen = verify_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = change_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_var_list(&head);

	return (new_input);
}
