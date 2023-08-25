#include "main.h"

/**
 * exit_command-handles exit command and exits the shell
 * @command: command and its arguments that were tokenized
 * from the user input
 * @line: input line provided by the user
 *
 * Return:void
 */
void exit_command(char **command, char *line)

{
	free(line);
	free_buffs(command);
	exit(0);
}

