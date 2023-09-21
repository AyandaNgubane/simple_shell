#include "shell.h"

char *builtin_cmds[] = {
	"cd",
	"env",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&_cd,
	&_env,
	&_help,
	&_exit_
};
/**
 * total_builtins - This gets the number of built in functions
 * Return: total
 */
int total_builtins(void)
{
	return (sizeof(builtin_cmds) / sizeof(char *));
}
/**
 * check_input - checks d  input for built in commands
 * @args: arguments from input
 * @name: argv
 * @envp: environmental variables
 * Return: ......
 */
int check_input(char **args, char **name, char **envp)
{
	int i;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < total_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_cmds[i]) == 0)
		{
			if (_strcmp(args[0], "env") == 0)
				return ((*builtin_func[i])(envp));
			return ((*builtin_func[i])(args));
		}
	}
	return (execute(args, name));
}
/**
 * _help - help menu
 * @args: arguments
 * Return: 1
 */
int _help(char **args)
{
	int i;

	_print("Type full command and press enter.\n");
	_print("We have the following commands available:\n");

	for (i = 0; i < total_builtins(); i++)
	{
		_print(builtin_cmds[i]);
		_print("\n");
	}
	args[0] = NULL;
	return (1);
}
/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int result;

	result = 0;

	for (i = 0; (s1[i] != '\0') || (s2[i] != '\0'); i++)
	{
		if (s1[i] > s2[i])
		{
			result = s1[i] - s2[i];
			break;
		}
		else if (s1[i] < s2[i])
		{
			result = s1[i] - s2[i];
			break;
		}
		else
		{
			continue;
		}
	}
	return (result);
}
