#include "shell.h"

/**
 * _exit_ - exits the shell
 * @args: user input
 * Return: 0
 */
int _exit_(char **args)
{
	if (args[1] == NULL)
		return (0);
	return (2);
}
/**
 * _env - prints environment variables
 * @envp: enviromental variables
 * Return: 1
 */
int _env(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		_print(envp[i]);
		_print("\n");
	}
	return (1);
}
/**
 * _cd - change directory
 * @args: user input
 * Return: 1
 */
int _cd(char **args)
{
	char *path;
	int rt;

	if (args[1] == NULL)
	{
		path = getenv("HOME");

		if (path == NULL)
			rt = chdir((path = getenv("PWD")) ? path : "/");
		else
			rt = chdir(path);
	}
	else
	{
		rt = chdir(args[1]);
	}
	return (1);
}
