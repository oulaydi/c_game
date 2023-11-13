#include "shell.h"

/**
 * err_enva - err message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *err_enva(all_data_shell *datash)
{
	int length;
	char *err;
	char *ver_str;
	char *msg;

	ver_str = _itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + _str_len(msg) + 4;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}

	_str_cpy(err, datash->av[0]);
	_str_cat(err, ": ");
	_str_cat(err, ver_str);
	_str_cat(err, ": ");
	_str_cat(err, datash->args[0]);
	_str_cat(err, msg);
	_str_cat(err, "\0");
	free(ver_str);

	return (err);
}
/**
 * err_path_126 - err message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The err string.
 */
char *err_path_126(all_data_shell *datash)
{
	int length;
	char *ver_str;
	char *err;

	ver_str = _itoa(datash->counter);
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + 24;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_str_cpy(err, datash->av[0]);
	_str_cat(err, ": ");
	_str_cat(err, ver_str);
	_str_cat(err, ": ");
	_str_cat(err, datash->args[0]);
	_str_cat(err, ": Permission denied\n");
	_str_cat(err, "\0");
	free(ver_str);
	return (err);
}
