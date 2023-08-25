#include "main.h"

/**
* append_path - adds path to command
* @path: path of command
* @command: user entered command
*
* Return: buffer containing command with path on success or
* NULL on failure
*/
char *append_path(char *path, char *command)
{
	char *buff;
	size_t i = 0, j = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buff = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buff)
		return (NULL);

	while (path[i])
	{
		buff[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buff[i] = '/';
		i++;
	}
	while (command[j])
	{
		buff[i + j] = command[j];
		j++;
	}
	buff[i + j] = '\0';
	return (buff);
}
