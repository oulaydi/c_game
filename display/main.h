#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
    char *type_arg;
    int (*f)(va_list, char *, unsigned int);
} display_t;

int _printf(const char *format, ...);
int display_prg(va_list __attribute__((unused)), char *, unsigned int);
int display_chr(va_list args, char *buf, unsigned int ibuf);
int display_str(va_list args, char *buf, unsigned int ibuf);
int display_int(va_list args, char *buf, unsigned int ibuf);
int display_bnr(va_list args, char *buf, unsigned int ibuf);
int display_unt(va_list args, char *buf, unsigned int ibuf);
int display_oct(va_list args, char *buf, unsigned int ibuf);
int display_hex(va_list args, char *buf, unsigned int ibuf);
int display_upx(va_list args, char *buf, unsigned int ibuf);
int display_usr(va_list args, char *buf, unsigned int ibuf);
int display_add(va_list args, char *buf, unsigned int ibuf);
int display_rev(va_list args, char *buf, unsigned int ibuf);
int display_rot(va_list args, char *buf, unsigned int ibuf);
int displaylint(va_list args, char *buf, unsigned int ibuf);
int displaylunt(va_list args, char *buf, unsigned int ibuf);
int displayloct(va_list args, char *buf, unsigned int ibuf);
int displaylhex(va_list args, char *buf, unsigned int ibuf);
int displaylupx(va_list args, char *buf, unsigned int ibuf);
int displayhint(va_list args, char *buf, unsigned int ibuf);
int displayhunt(va_list args, char *buf, unsigned int ibuf);
int displayhoct(va_list args, char *buf, unsigned int ibuf);
int displayhhex(va_list args, char *buf, unsigned int ibuf);
int displayhupx(va_list args, char *buf, unsigned int ibuf);
int displaypint(va_list args, char *buf, unsigned int ibuf);
int displaynoct(va_list args, char *buf, unsigned int ibuf);
int displaynhex(va_list args, char *buf, unsigned int ibuf);
int displaynupx(va_list args, char *buf, unsigned int ibuf);
int displaysint(va_list args, char *buf, unsigned int ibuf);

int (*get_display_func(const char *s, int idx))(va_list, char *, unsigned int);
int ev_display_func(const char *s, int index);
unsigned int grip_buf(char *buf, char c, unsigned int ibuf);
int display_buf(char *buf, unsigned int nbuf);
char *load_binary_array(char *binary, long int int_in, int isneg, int limit);
char *load_oct_array(char *bnr, char *oct);
char *load_long_oct_array(char *bnr, char *oct);
char *load_short_oct_array(char *bnr, char *oct);
char *load_hex_array(char *bnr, char *hex, int isupp, int limit);

#endif