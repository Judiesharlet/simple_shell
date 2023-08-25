#include "main.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: array of strings
 *
 * Return: 0 if success -1 otherwise
 */
int main(int ac, char **av)
{
	char *lineptr = NULL, *command_path = NULL, *path = NULL;
	size_t len = 0;
	ssize_t num_chars = 0;
	char **command = NULL, **paths = NULL;
	(void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_buffs(command);
		free_buffs(paths);
		free(command_path);
		print_prompt();
		num_chars = getline(&lineptr, &len, stdin);
		if (num_chars < 0)
			break;
		info.ln_count++;
		if (lineptr[num_chars - 1] == '\n')
			lineptr[num_chars - 1] = '\0';
		command = tokenizeLine(lineptr);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (builtin_checker(command, lineptr))
			continue;
		path = find_path();
		paths = tokenizeLine(path);
		command_path = test_path(paths, command[0]);
		if (!command_path)
			perror(av[0]);
		else
			execute_command(command_path, command);
	}
	if (num_chars < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(lineptr);
	return (0);
}
