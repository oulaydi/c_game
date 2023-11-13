#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define TOK_BUFFER_SIZE 128
#define TOKEN_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} all_data_shell;

/**
 * struct sepa_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sepa_list_s
{
	char separator;
	struct sepa_list_s *next;
} sepa_list;

/**
 * struct line_st_str - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_st_str
{
	char *line;
	struct line_st_str *next;
} line_list_s;

/**
 * struct str_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct str_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct str_var_list *next;
} str_var;

/**
 * struct cmp_t - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct cmp_t
{
	char *name;
	int (*f)(all_data_shell *datash);
} cmp_t;

/* aux_lists.c */
sepa_list *add_sepa_to_end(sepa_list **head, char sep);
void free_sepa_list(sepa_list **head);
line_list_s *add_line_to_end(line_list_s **head, char *line);
void free_line_list_s(line_list_s **head);

/* aux_lists2.c */
str_var *var_to_node(str_var **head, int lvar, char *var, int lval);
void free_var_list(str_var **head);

/* aux_str functions */
char *_str_cat(char *dest, const char *src);
char *_str_cpy(char *dest, char *src);
int _str_cmp(char *s1, char *s2);
char *_str_chr(char *s, char c);
int _str_spn(char *s, char *accept);

/* aux_mem.c */
void _mem_cpy(void *newptr, const void *ptr, unsigned int size);
void *_realc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_realc_dp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *_str_dup(const char *s);
int _str_len(const char *s);
int cmp_str(char str[], const char *delim);
char *_str_tok(char str[], const char *delim);
int _is_a_digit(const char *s);

/* aux_str3.c */
void rev_str(char *s);

/* verify_stx_err.c */
int loop_char(char *input, int i);
int err_sepa_op(char *input, int i, char last);
int fst_char(char *input, int *i);
void display_stx_err(all_data_shell *datash, char *input, int i, int bool);
int verify_stx_err(all_data_shell *datash, char *input);

/* shell_fori.c */
char *not_cmtr(char *in);
void shell_fori(all_data_shell *datash);

/* play_line.c */
char *play_line(int *i_eof);

/* split.c */
char *swap_to_char(char *input, int bool);
void instert_sepa(sepa_list **head_s, line_list_s **head_l, char *input);
void _next(sepa_list **list_s, line_list_s **list_l, all_data_shell *datash);
int qsem_cmd(all_data_shell *datash, char *input);
char **qsem_line(char *input);

/* rep_str.c */
void verify_enva(str_var **h, char *in, all_data_shell *data);
int verify_vars(str_var **h, char *in, char *st, all_data_shell *data);
char *change_input(str_var **head, char *input, char *new_input, int nlen);
char *rep_str(char *input, all_data_shell *datash);

/* next_line.c */
void get_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t next_line(char **lineptr, size_t *n, FILE *stream);

/* exe_line */
int exe_line(all_data_shell *datash);

/* cmd_exe.c */
int cur_dir(char *path, int *i);
char *inahowa(char *cmd, char **_environ);
int is_exe(all_data_shell *datash);
int verify_err_cmd(char *dir, all_data_shell *datash);
int cmd_exe(all_data_shell *datash);

/* env1.c */
char *_get_enva(const char *name, char **_environ);
int _enva(all_data_shell *datash);

/* env2.c */
char *cp_info(char *name, char *value);
void set_enva(char *name, char *value, all_data_shell *datash);
int _set_env(all_data_shell *datash);
int _unset_env(all_data_shell *datash);

/* cd.c */
void cd_no9ta(all_data_shell *datash);
void cd_path(all_data_shell *datash);
void joj_no9at(all_data_shell *datash);
void cd_oulaydi(all_data_shell *datash);

/* change_cur.c */
int change_cur(all_data_shell *datash);

/* get_cmp */
int (*get_cmp(char *cmd))(all_data_shell *datash);

/* _exit.c */
int exit_ter(all_data_shell *datash);

/* aux_stdlib.c */
int get_len(int n);
char *_itoa(int n);
int _ato_i(char *s);

/* aux_err1.c */
char *str_cat_cd(all_data_shell *, char *, char *, char *);
char *err_get_cd(all_data_shell *datash);
char *err_404(all_data_shell *datash);
char *err_exit_ter(all_data_shell *datash);

/* aux_err2.c */
char *err_get_as(char **args);
char *err_enva(all_data_shell *datash);
char *err_stx(char **args);
char *err_chmod(char **args);
char *err_path_126(all_data_shell *datash);

/* get_err.c */
int get_err(all_data_shell *datash, int eval);

/* get_ctrlC.c */
void get_ctrlC(int sig);

/* aux_help.c */
void _help_enva(void);
void _help_set_env(void);
void _help_unset_env(void);
void _help_general(void);
void _help_exit(void);

/* aux_help2.c */
void _help(void);
void _help_as(void);
void _help_cd(void);

/* need_help.c */
int need_help(all_data_shell *datash);

#endif
