#include "main.h"

/**
 * recuperate_sigint - Handle the crtl + c call in prompt
 * @sig_h: Signal handler
 */
void recuperate_sigint(int sig_h)
{
	(void)sig_h;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
