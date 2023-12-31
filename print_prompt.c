#include "main.h"

/**
 * print_prompt - prints prompt $ if the shell is in interactive mode
 *
 * Return: void
 */

void print_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
