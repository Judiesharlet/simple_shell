#include "main.h"

/**
 * print_env - prints the current environment
 *
 * Return: void
 */

void print_env(void)
{
	int i = 0;

	char **env_var = environ;

	while (env_var[i])

	{
		write(STDOUT_FILENO, (const void *)env_var[i], _strlen(env_var[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

