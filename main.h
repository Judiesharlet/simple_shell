#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>


extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/**
 * struct builtin - struct for builtin functions
 *
 * @env: pointer to a string that represents the environment
 * related command that can be executed in the shell
 * @exit: pointer to a string that represents the command
 * that is used to exit shell
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct info - struct for final exit information
 *
 * @final_exit: stores the exit status of the last executed
 * command or operation
 * @ln_count: number of lines read or executed during the
 * shell's operation
 */
struct info
{
	int final_exit;
	int ln_count;
} info;
/**
 * struct flags - struct for interactive mode
 *
 * @interactive: flag that indicates whether the shell is running
 * in interactive mode
 */

struct flags
{

	bool interactive;

} flags;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);



void print_prompt(void);
void handle_signal(int n);
char **tokenizeLine(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
char *find_path(void);
int builtin_checker(char **command, char *buff);
int handle_builtin(char **command, char *line);
void exit_command(char **command, char *line);
void print_env(void);
void execute_command(char *cmd, char **av);
void free_buffs(char **buff);

#endif
