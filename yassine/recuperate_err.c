#include "main.h"

/**
 * recuperate_err - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int recuperate_err(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = err_env(datash);
		break;
	case 126:
		error = err_path_chmod(datash);
		break;
	case 127:
		error = err_not_404(datash);
		break;
	case 2:
		if (_str_cmp("exit", datash->args[0]) == 0)
			error = err_quit_shell(datash);
		else if (_str_cmp("cd", datash->args[0]) == 0)
			error = err_get_cd(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _str_len(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
