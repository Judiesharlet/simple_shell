#include "main.h"

/**
 * find_path - finds the path from the global enviroment
 *
 * Return: path if path is found or NULL if it is not found
 */
char *find_path(void)
{
	char **env_var = environ;
	char *path = NULL;
	int i;

	while (*env_var)
	{
		if (_strncmp(*env_var, "PATH=", 5) == 0)
		{
			path = *env_var;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env_var++;
	}
	return (NULL);
}
