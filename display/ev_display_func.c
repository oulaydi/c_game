#include "main.h"

/**
 * ev_display_func - returns the amount of identifiers.
 * @s: argument indentifier
 * @index: index of argument identifier.
 * Return: amount of identifiers.
 */
int ev_display_func(const char *s, int index)
{
	display_t pr[] = {
		{"c", display_chr}, {"s", display_str}, {"i", display_int},
		{"d", display_int}, {"b", display_bnr}, {"u", display_unt},
		{"o", display_oct}, {"x", display_hex}, {"X", display_upx},
		{"S", display_usr}, {"p", display_add}, {"li", displaylint},
		{"ld", displaylint}, {"lu", displaylunt}, {"lo", displayloct},
		{"lx", displaylhex}, {"lX", displaylupx}, {"hi", displayhint},
		{"hd", displayhint}, {"hu", displayhunt}, {"ho", displayhoct},
		{"hx", displayhhex}, {"hX", displayhupx}, {"#o", displaynoct},
		{"#x", displaynhex}, {"#X", displaynupx}, {"#i", display_int},
		{"#d", display_int}, {"#u", display_unt}, {"+i", displaypint},
		{"+d", displaypint}, {"+u", display_unt}, {"+o", display_oct},
		{"+x", display_hex}, {"+X", display_upx}, {" i", displaysint},
		{" d", displaysint}, {" u", display_unt}, {" o", display_oct},
		{" x", display_hex}, {" X", display_upx}, {"R", display_rot},
		{"r", display_rev}, {"%", display_prg}, {"l", display_prg},
		{"h", display_prg}, {" +i", displaypint}, {" +d", displaypint},
		{"+ i", displaypint}, {"+ d", displaypint}, {" %", display_prg},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (j);
}
