#include "main.h"

/**
 * recuperate_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int recuperate_help(all_data_shell *datash)
{

	if (datash->args[1] == 0)
		help_general();
	else if (_str_cmp(datash->args[1], "setenv") == 0)
		help_set_env();
	else if (_str_cmp(datash->args[1], "env") == 0)
		help_env();
	else if (_str_cmp(datash->args[1], "unsetenv") == 0)
		help_unsetenv();
	else if (_str_cmp(datash->args[1], "help") == 0)
		help();
	else if (_str_cmp(datash->args[1], "exit") == 0)
		help_quit();
	else if (_str_cmp(datash->args[1], "cd") == 0)
		help_cd();
	else if (_str_cmp(datash->args[1], "alias") == 0)
		help_as();
	else
		write(STDERR_FILENO, datash->args[0],
		      _str_len(datash->args[0]));

	datash->status = 0;
	return (1);
}
