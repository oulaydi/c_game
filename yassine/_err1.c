
#include "shell.h"

/**
 * str_cat_cd - function that concatenates the message for cd err
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @err: output message
 * @ver_str: counter lines
 * Return: err message
 */
char *str_cat_cd(all_data_shell *datash, char *msg, char *err, char *ver_str)
{
	char *illegal_flag;

	_str_cpy(err, datash->av[0]);
	_str_cat(err, ": ");
	_str_cat(err, ver_str);
	_str_cat(err, ": ");
	_str_cat(err, datash->args[0]);
	_str_cat(err, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_str_cat(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_str_cat(err, datash->args[1]);
	}

	_str_cat(err, "\n");
	_str_cat(err, "\0");
	return (err);
}

/**
 * err_get_cd - err message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: err message
 */
char *err_get_cd(all_data_shell *datash)
{
	int length, len_id;
	char *err, *ver_str, *msg;

	ver_str = _itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _str_len(datash->args[1]);
	}

	length = _str_len(datash->av[0]) + _str_len(datash->args[0]);
	length += _str_len(ver_str) + _str_len(msg) + len_id + 5;
	err = malloc(sizeof(char) * (length + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = str_cat_cd(datash, msg, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * err_404 - generic err message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: err message
 */
char *err_404(all_data_shell *datash)
{
	int length;
	char *err;
	char *ver_str;

	ver_str = _itoa(datash->counter);
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + 16;
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
	_str_cat(err, ": not found\n");
	_str_cat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * err_exit_ter - generic err message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: err message
 */
char *err_exit_ter(all_data_shell *datash)
{
	int length;
	char *err;
	char *ver_str;

	ver_str = _itoa(datash->counter);
	length = _str_len(datash->av[0]) + _str_len(ver_str);
	length += _str_len(datash->args[0]) + _str_len(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_str_cpy(err, datash->av[0]);
	_str_cat(err, ": ");
	_str_cat(err, ver_str);
	_str_cat(err, ": ");
	_str_cat(err, datash->args[0]);
	_str_cat(err, ": Illegal number: ");
	_str_cat(err, datash->args[1]);
	_str_cat(err, "\n\0");
	free(ver_str);

	return (err);
}
