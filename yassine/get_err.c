#include "shell.h"

/**
 * get_err - calls the err according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: err value
 * Return: err
 */
int get_err(all_data_shell *datash, int eval)
{
	char *err;

	switch (eval)
	{
	case -1:
		err = err_enva(datash);
		break;
	case 126:
		err = err_path_126(datash);
		break;
	case 127:
		err = err_404(datash);
		break;
	case 2:
		if (_str_cmp("exit", datash->args[0]) == 0)
			err = err_exit_ter(datash);
		else if (_str_cmp("cd", datash->args[0]) == 0)
			err = err_get_cd(datash);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _str_len(err));
		free(err);
	}

	datash->status = eval;
	return (eval);
}
