#include "main.h"
#define FREE_RESOURCES           \
	{                            \
		free_double_arr(&paths); \
		free(pathCpy);           \
	}
/**
 * is_executable_in_env_paths - is a function that verifies whether
 * a given input is an executable file or an alias for an executable file.
 * Description: The function performs the following checks:
 *
 * 1. Checks if the input corresponds to an executable file. That is,
 * it verifies
 * if the file exists in the current directory and has execute permissions.
 *
 * 2- If the input is an alias, the function checks if it corresponds
 * to an executable file present in the directories listed in the `PATH`
 *  environment variable.
 *
 * @params:
 * @input: the first word in  command line that user inputs
 *
 * * Return: a pointer to the path if its exist or NULL if now exist
 */

char *is_executable_in_env_paths(char *input)
{
	int i = 0, is_executable;
	int is_full_path = (input[0] == '.' || input[0] == '/');
	char *path = _getEnv("PATH="), *pathCpy, **paths;

	if (is_full_path && access(input, X_OK) == 0)
	{
		pathCpy = strdup(input);
		return (pathCpy);
	}
	if (path == NULL)
	{
		fprintf(stderr, "%s: %i: %s: not found\n", app_name, counter, input);
		return (NULL);
	}
	pathCpy = strdup(path);
	paths = tokenize_string(pathCpy, ":=");
	while (paths[i] != NULL)
	{
		if (append_to_path(&paths[i], input) == -1)
		{
			fprintf(stderr, "Memory allocation failed");
			FREE_RESOURCES;
			return (NULL);
		}
		is_executable = access(paths[i], X_OK);
		if (is_executable == 0)
		{
			char *found_path = strdup(paths[i]);

			FREE_RESOURCES;
			return (found_path);
		}
		i++;
	}
	free_double_arr(&paths);
	free(pathCpy);
	if (is_executable != 0)
		fprintf(stderr, "%s: %i: %s: not found\n",
				app_name, counter, input);
	return (NULL);
}
/**
 * append_to_path - function that take a path and input
 * then append the input to the path
 *
 * @path: a pointer to 2d array of paths
 * @input: input to be appended to the path
 *
 * Return: 1 in success and -1 in failure
 */
int append_to_path(char **path, char *input)
{
	int input_len = strlen(input), path_len = strlen(*path);

	/* +2 for the slash and null terminator*/
	char *tmp;

	tmp = realloc(*path, sizeof(char) * (path_len + input_len + 2));

	if (tmp == NULL)
	{
		fprintf(stderr, "Memory reallocation failed.\n");
		return (-1);
	}

	*path = tmp;

	strcat(*path, "/");
	strcat(*path, input);

	/* return success*/
	return (0);
}
