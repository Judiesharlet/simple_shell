#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void print_prompt(char *prompt);
char **tokenizeLine(char *str, const char *delim);
void execute_command(char **av);
void execute_pipeline(char **av, int pipe_index);
char *get_path(char *command);
int exit_command(char *command);
void print_env(void);

#endif
