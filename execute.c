#include "shell.h"

/**
 * execute - opens a new process/program
 * @args: user input
 * @name: argv
 * Return: 1
 */
int execute(char **args, char **name)
{
	pid_t pid;
	int status;
	char *command = NULL, *path = NULL;

	command = args[0];

	path = pathfinder(command, name);

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
			perror(name[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror(name[0]);
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
/**
 * pathfinder - finds the path of the command
 * @command: user input
 * @name: argv
 * Return: path
 */
char *pathfinder(char *command, char **name)
{
	char *_file, *path, *dup_path, *args;
	int length, length_dir;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		dup_path = strdup(path);
		length = strlen(command);
		args = strtok(dup_path, ":");

		while (args != NULL)
		{
			length_dir = strlen(args);
			_file = malloc(length + length_dir + 2);

			if (!_file)
			{
				_print(name[0]);
				_print(": error allocating memory\n");
				return (NULL);
			}
			_strcpy(_file, args), _strcat(_file, "/"), _strcat(_file, command);
			_strcat(_file, "\0");
			if (stat(_file, &buffer) == 0)
			{
				free(dup_path);
				return (_file);
			}
			else
				free(_file), args = strtok(NULL, ":");
		}
		free(dup_path);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
/**
 * _strcpy - copies string
 *
 * @dest: where to store copied string
 * @src: string to copy
 * Return: return the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}
/**
 * _strcat - appends the src string to the dest string
 *
 * @dest: destination
 * @src: string to append
 * Return: the full string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
