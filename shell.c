#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: ...
 */
int main(int argc, char *argv[], char **envp)
{
	char *input, **args;
	int check;

	if (argc < 0)
		return (-1);

	do {
		_print("$ ");
		input = user_input();
		args = tokenizer(input, argv);
		check = check_input(args, argv, envp);
		free(input);
		free(args);
	} while (check);
	return (EXIT_SUCCESS);
}
/**
 * _print - printing function
 * @str: string to print
 * Return: void
 */
void _print(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * _strlen - counts length of string
 *
 * @s: string to be checked
 * Return: length
 */
int _strlen(char *s)
{
	int i;
	int length;

	length = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}
/**
 * user_input - reads the user input
 * Return: input
 */
char *user_input(void)
{
	char *input = NULL;
	size_t buffer = 0;

	if (getline(&input, &buffer, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("userinput");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
