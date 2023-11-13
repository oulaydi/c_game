#include "shell.h"

/**
 * cp_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *cp_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _str_len(name);
	len_value = _str_len(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_str_cpy(new, name);
	_str_cat(new, "=");
	_str_cat(new, value);
	_str_cat(new, "\0");

	return (new);
}

/**
 * set_enva - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_enva(char *name, char *value, all_data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _str_dup(datash->_environ[i]);
		name_env = _str_tok(var_env, "=");
		if (_str_cmp(name_env, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = cp_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _realc_dp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = cp_info(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _set_env - compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _set_env(all_data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_err(datash, -1);
		return (1);
	}

	set_enva(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unset_env - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unset_env(all_data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_err(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _str_dup(datash->_environ[i]);
		name_env = _str_tok(var_env, "=");
		if (_str_cmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_err(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[k]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
