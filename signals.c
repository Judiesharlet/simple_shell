#include "main.h"

/**
 * handle_signal - keeps track of signal in interactive mode
 * @n: the signal number
 *
 * Retrun:void
 */
void handle_signal(int n)
{
	(void)n;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$", 2);

}
