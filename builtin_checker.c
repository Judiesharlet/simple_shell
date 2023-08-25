#include "main.h"

/**
 * builtin_checker- checks to see if its a builtin function
 * @command: tokenized user input
 * @buff: line derived from getline function
 *
 * Return: 1 if command is executed 0 otherwise
 */
int builtin_checker(char **command, char *buff)
{
	if (handle_builtin(command, buff))
		return (1);
	else if (**command == '/')
	{
		execute_command(command[0], command);
		return (1);
	}
	return (0);
}
