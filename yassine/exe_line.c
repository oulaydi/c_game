#include "shell.h"

/**
 * exe_line - finds builtins and commands
 *
 * @datash: data relevant (args)
 * Return: 1 on success.
 */
int exe_line(all_data_shell *datash)
{
	int (*builtin)(all_data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_cmp(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exe(datash));
}
