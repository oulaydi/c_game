#include "shell.h"

/**
 * get_ctrlC - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_ctrlC(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
