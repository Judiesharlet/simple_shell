#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be used
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
	int l = 0;

	for (; *s != '\0'; s++)
	{
		l++;
	}
	return (l);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: Always 0 (Success)
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')

	{
		if (s1[a] != s2[a])

		{
			return (s1[a] - s2[a]);

		}

		a++;
	}

		return (0);
}

/**
* _strdup - dupicates string
* @s: string to be duplicated
*
* Return: pointer to duplicate string
*/
char *_strdup(char *s)
{
	char *dupptr;
	int i, length;

	if (s == NULL)

		return (NULL);

	length = _strlen(s);

	dupptr = malloc(sizeof(char) * (length + 1));

	if (dupptr == NULL)

		return (NULL);

	for (i = 0; *s != '\0'; s++, i++)

		dupptr[i] = s[0];

	dupptr[i++] = '\0';

	return (dupptr);

}

/**
 * _strncmp - compares two strings up to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes
 *
 * Return: difference between s1 and s2
 */
int _strncmp(char *s1, char *s2, int n)

{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
		{
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
		}

	return (0);

}
/**
 * _strchr - finds a char in a string
 * @s: the string
 * @c: char to be located
 *
 * Return: pointer to first occurence of character
 * or NULL if char is not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
	if (*s == c)
		return (s);
	s++;
	}

	if (!c)
		return (s);
	return (NULL);
}

