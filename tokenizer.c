#include "shell.h"

#define DELIM " \t\r\n\a"

/**
 * tokenizer - splits user input into arguments
 * @input: user input
 * @name: argv
 * Return: arguments
 */
char **tokenizer(char *input, char *name[])
{
	unsigned int prv_buffer, i = 0, buffer = 64;
	char *tok;
	char **args = malloc(buffer * sizeof(char *));

	if (!args)
	{
		_print(name[0]);
		_print(": error allocating memory\n");
		return (NULL);
	}

	tok = strtok(input, DELIM);
	while (tok != NULL)
	{
		args[i] = tok;
		i++;

		if (buffer <= i)
		{
			prv_buffer = buffer;
			buffer = buffer + 64;
			args = _realloc(args, prv_buffer * sizeof(char *), buffer * sizeof(char *));
			if (!args)
			{
				_print(name[0]);
				_print(": error allocating memory\n");
				return (NULL);
			}
		}
		tok = strtok(NULL, DELIM);
	}
	args[i] = NULL;
	return (args);
}
/**
  * _realloc - similar to realloc
  * @ptr: previously allocated memory
  * @old_size: size of previously allocated memory
  * @new_size: new size
  *
  * Return: pointer
  */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
	{
		new_ptr[i] = ((char *) ptr)[i];
	}
	free(ptr);
	return (new_ptr);
}
