#include "shell.h"

/**
 * need_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int need_help(all_data_shell *datash)
{

	if (datash->args[1] == 0)
		_help_general();
	else if (_str_cmp(datash->args[1], "setenv") == 0)
		_help_set_env();
	else if (_str_cmp(datash->args[1], "env") == 0)
		_help_enva();
	else if (_str_cmp(datash->args[1], "unsetenv") == 0)
		_help_unset_env();
	else if (_str_cmp(datash->args[1], "help") == 0)
		_help();
	else if (_str_cmp(datash->args[1], "exit") == 0)
		_help_exit();
	else if (_str_cmp(datash->args[1], "cd") == 0)
		_help_cd();
	else if (_str_cmp(datash->args[1], "alias") == 0)
		_help_as();
	else
		write(STDERR_FILENO, datash->args[0],
		      _str_len(datash->args[0]));

	datash->status = 0;
	return (1);
}
