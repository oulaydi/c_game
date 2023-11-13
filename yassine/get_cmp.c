#include "shell.h"

/**
 * get_cmp - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*get_cmp(char *cmd))(all_data_shell *)
{
	cmp_t builtin[] = {
		{"env", _env},
		{"exit", exit_ter},
		{"setenv", _set_env},
		{"unsetenv", _unset_env},
		{"cd", change_cur},
		{"help", need_help},
		{NULL, NULL}};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_str_cmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
