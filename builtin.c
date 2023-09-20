#include "shell.h"

/**
 * _exit_ - exits the shell
 * @args: user input
 * Return: 0
 */
int _exit_(char **args)
{
	args[0] = NULL;
	write(STDOUT_FILENO, "exit\n", strlen("exit\n"));
	exit(EXIT_SUCCESS);
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
	if (args[1] == NULL)
	{
		_print("Wrong use of command\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("shell");
		}
	}
	return (1);
}
