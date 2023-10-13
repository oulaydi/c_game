#include "main.h"
/**
 * get_display_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @idx: idx for argument indentifier
 * Return: pointer to a function.
 */
int (*get_display_func(const char *s, int idx))(va_list, char *, unsigned int)
{
	display_t pr[] = {
		{"c", display_chr}, {"s", display_str},
		{"i", display_int}, {"d", display_int},
		{"b", display_bnr}, {"u", display_unt},
		{"o", display_oct}, {"x", display_hex},
		{"X", display_upx}, {"S", display_usr},
		{"p", display_add}, {"li", displaylint},
		{"ld", displaylint}, {"lu", displaylunt},
		{"lo", displayloct}, {"lx", displaylhex},
		{"lX", displaylupx}, {"hi", displayhint},
		{"hd", displayhint}, {"hu", displayhunt},
		{"ho", displayhoct}, {"hx", displayhhex},
		{"hX", displayhupx}, {"#o", displaynoct},
		{"#x", displaynhex}, {"#X", displaynupx},
		{"#i", display_int}, {"#d", display_int},
		{"#u", display_unt}, {"+i", displaypint},
		{"+d", displaypint}, {"+u", display_unt},
		{"+o", display_oct}, {"+x", display_hex},
		{"+X", display_upx}, {" i", displaysint},
		{" d", displaysint}, {" u", display_unt},
		{" o", display_oct}, {" x", display_hex},
		{" X", display_upx}, {"R", display_rot},
		{"r", display_rev}, {"%", display_prg},
		{"l", display_prg}, {"h", display_prg},
		{" +i", displaypint}, {" +d", displaypint},
		{"+ i", displaypint}, {"+ d", displaypint},
		{" %", display_prg}, {NULL, NULL},
	};
	int i = 0, j = 0, first_idx;

	first_idx = idx;
	while (pr[i].type_arg)
	{
		if (s[idx] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				idx++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			idx = first_idx;
		}
	}
	return (pr[i].f);
}
