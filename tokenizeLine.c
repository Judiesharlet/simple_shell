#include "main.h"

/**
 * tokenizeLine - tokenizes a string into an array of words
 * @line: pointer to the input string that you want to tokenize
 *
 * Return: array of strings (tokens) that were extracted
 * from the input string
 */

char **tokenizeLine(char *line)
{
	char *lineptr = NULL, *lineptr_copy = NULL;
	char *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int token_count = 1;
	size_t i = 0, flag = 0;

	lineptr = _strdup(line);
	if (!lineptr)
		return (NULL);
	lineptr_copy = lineptr;

	while (*lineptr_copy)
	{
		if (_strchr(delim, *lineptr_copy) != NULL && flag == 0)
		{
			token_count++;
			flag = 1;
		}
		else if (_strchr(delim, *lineptr_copy) == NULL && flag == 1)
			flag = 0;
		lineptr_copy++;
	}
	tokens = malloc(sizeof(char *) * (token_count + 1));
	token = strtok(lineptr, delim);
	while (token)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = '\0';
	free(lineptr);
	return (tokens);
}
