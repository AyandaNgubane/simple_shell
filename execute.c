#include "shell.h"

/**
 * execute - This opens new process/program
 * @args: the user input
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
	if (path == NULL)
	{
		write(STDERR_FILENO, name[0], _strlen(name[0]));
		write(STDERR_FILENO, ": ", _strlen(": "));
		perror(command);
		free(path);
		return (-1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			write(STDERR_FILENO, name[0], _strlen(name[0]));
			write(STDERR_FILENO, ": 1: ", _strlen(": 1: "));
			write(STDERR_FILENO, command, _strlen(command));
			write(STDERR_FILENO, ": not found\n", _strlen(": not found\n"));
		}
		exit(127);
	}
	else if (pid < 0)
		perror(name[0]);
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (_strcmp(command, path) != 0)
		free(path);
	return (1);
}
/**
 * pathfinder - it finds d path of the command
 * @command: user input
 * @name: argv
 * Return: path
 */
char *pathfinder(char *command, char **name)
{
	char *_file, *path, *dup_path = NULL, *args = NULL;
	int length, length_dir;
	struct stat buffer;

	path = getenv("PATH");

	if (stat(command, &buffer) == 0)
		return (command);
	if (path)
	{
		dup_path = _strdup(path);
		length = _strlen(command);
		args = strtok(dup_path, ":");

		while (args != NULL)
		{
			length_dir = _strlen(args);
			_file = malloc(length + length_dir + 2);

			if (!_file)
			{
				_print(name[0]);
				_print(": error allocating memory\n");
				return (NULL);
			}
			_strcpy(_file, args), _strcat(_file, "/"), _strcat(_file, command);
			if (stat(_file, &buffer) == 0)
			{
				free(dup_path);
				return (_file);
			}
			else
				free(_file), args = strtok(NULL, ":");
		}
		free(dup_path);
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
/**
 * _strdup - works similar to strdup
 *
 * @str: string to be checked
 * Return: pointer if successful or NULL if it fails
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int j, length;

	length = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		length++;
	}

	ptr = malloc(length + 1);

	if (ptr == NULL)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		ptr[j] = str[j];
	}
	return (ptr);
}
