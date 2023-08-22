#include "main.h"
char *is_executable_in_env_paths(char *input, int command_count, char *app_name)
{
	int i = 0, is_executable;
	int is_full_path = (input[0] == '.' || input[0] == '/');
	char *path = _getEnv("PATH="), *pathCpy, **paths;

	if (is_full_path && access(input, X_OK) == 0)
	{
		pathCpy = strdup(input);
		return pathCpy;
	}
	if (path == NULL)
	{
		fprintf(stderr, "%s: %i: %s: not found\n", app_name, command_count, input);
		return NULL;
	}
	pathCpy = strdup(path);
	paths = tokenize_string(pathCpy, ":=");
	while (paths[i] != NULL)
	{
		if (append_to_path(&paths[i], input) == -1)
		{
			fprintf(stderr, "Memory allocation failed");
			free_double_arr(paths);
			free(pathCpy);
			return NULL;
		}

		if ((is_executable = access(paths[i], X_OK)) == 0)
		{
			char *found_path = strdup(paths[i]);

			free_double_arr(paths);
			free(pathCpy);
			return found_path;
		}
		i++;
	}
	free_double_arr(paths);
	free(pathCpy);
	if (is_executable != 0)
		fprintf(stderr, "%s: %i: %s: not found\n", app_name, command_count, input);
	return NULL;
}

int append_to_path(char **path, char *input)
{
	int input_len = strlen(input), path_len = strlen(*path);

	/* +2 for the slash and null terminator*/
	char *tmp;
	tmp = realloc(*path, sizeof(char) * (path_len + input_len + 2));

	if (tmp == NULL)
	{
		fprintf(stderr, "Memory reallocation failed.\n");
		return -1;
	}

	*path = tmp;

	strcat(*path, "/");
	strcat(*path, input);

	/* return success*/
	return 0;
}
