#include "main.h"

/**
 * print_prompt-prints prompt
 * @prompt: the prompt to print
 *
 * Return:void
 */
void print_prompt(char *prompt)

{
	write(STDOUT_FILENO, prompt _strlen(prompt));
}

