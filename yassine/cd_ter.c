#include "shell.h"

/**
 * change_cur - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int change_cur(all_data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = _str_cmp("$HOME", dir);
		ishome2 = _str_cmp("~", dir);
		isddash = _str_cmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_oulaydi(datash);
		return (1);
	}

	if (_str_cmp("-", dir) == 0)
	{
		joj_no9at(datash);
		return (1);
	}

	if (_str_cmp(".", dir) == 0 || _str_cmp("..", dir) == 0)
	{
		cd_no9ta(datash);
		return (1);
	}

	cd_path(datash);

	return (1);
}
