#ifndef SHELL_H
#define SHELL_H

#define DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void _print(char *str);
char *user_input(void);
int _strlen(char *s);
int execute(char **args, char **name);
char *pathfinder(char *command, char **name);
int total_builtins(void);
int check_input(char **args, char **name, char **envp);
int _help(char **args);
int _strcmp(char *s1, char *s2);
int _exit_(char **args);
int _cd(char **args);
char **tokenizer(char *input, char *name[]);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _env(char **envp);
char *_strdup(char *str);

#endif
