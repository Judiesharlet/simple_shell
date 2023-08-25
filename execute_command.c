#include "main.h"

/**
 * execute_command - executes a command with arguments
 * @cmd: the command
 * @av: double pointer to an array of strings
 *
 * Return: void
 */

void execute_command(char *cmd, char **av)
{
	pid_t child_pid;
	int status;
	char **env_var = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cmd);
	if (child_pid == 0)
	{
		execve(cmd, av, env_var);
		perror(cmd);
		free(cmd);
		free_buffs(av);
		exit(98);
	}
	else
		wait(&status);
}
