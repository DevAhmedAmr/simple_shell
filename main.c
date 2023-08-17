#include "main.h"
int check_is_executable_in_paths(char *input);
void printArgs(char **args);
int append_to_path(char **path, char *input);
int main(void)
{
	char *cmd = NULL, **args = NULL, ***threeD_arr = NULL, *token = NULL;
	int interActive = isatty(STDIN_FILENO);
	size_t i;

	if (!interActive)
	{
		non_interactive(&cmd, &args);
		free(cmd);
	}
	else
		while (1)
		{
			write(STDIN_FILENO, "$ ", 2);

			args = malloc(sizeof(char *) * 50);

			if (interactive_mode(&cmd, &args) == EOF)
			{
				write(STDIN_FILENO, "\n", 1);
				exit(127);
			}

			// printArgs(args);

			if (args[0] != NULL)
				check_is_executable_in_paths(args[0]);

			/*free mem*/

			free(cmd);
			free_double_arr(args);
		}
}

void print3d_arr(char ***threeD_arr)
{
	for (size_t i = 0; threeD_arr[i] != NULL; i++)
	{
		char **token = threeD_arr[i];

		for (size_t j = 0; token[j] != NULL; j++)
		{
			printf(" %s", token[j]);

			if (token[j + 1] != NULL)

				putchar(',');
		}
		putchar('\n');
	}
}

int check_is_executable_in_paths(char *input)
{
	int i = 0, is_executable;
	char *path = _getEnv("PATH=");
	char *pathCpy, **pathsArray;

	if (path == NULL)
	{
		fprintf(stderr, "path is not found");
		return -1;
	}

	pathCpy = strdup(path);

	pathsArray = tokenize_string(pathCpy, ":=");

	while (pathsArray[i] != NULL)
	{
		if (append_to_path(&pathsArray[i], input) == -1)
		{
			fprintf(stderr, "Memory allocation failed");
			free_double_arr(pathsArray);
			free(pathCpy);
			return -1;
		}
		if ((is_executable = access(pathsArray[i], X_OK)) == 0)
		{
			printf("%s\n\n", pathsArray[i]);
			break;
		}

		i++;
	}

	free_double_arr(pathsArray);
	free(pathCpy);

	if (is_executable)
		fprintf(stderr, "Executable file '%s' not found in any PATH\n", input);

	return is_executable;
}
void printArgs(char **args)
{
	for (size_t j = 0; args[j] != NULL; j++)
	{
		printf("argv :: %s\n", args[j]);
	}
}

int append_to_path(char **path, char *input)
{
	int input_len = strlen(input), path_len = strlen(*path);

	/* +2 for the slash and null terminator*/
	char *tmp = realloc(*path, sizeof(char) * (path_len + input_len + 2));

	if (tmp == NULL)
	{
		fprintf(stderr, "Memory reallocation failed.\n");
		return -1; // return error on failure
	}

	*path = tmp;

	strcat(*path, "/");
	strcat(*path, input);

	// return success
	return 0;
}
// int forkk(char *input, char **args)
// {
// 	pid_t pid = fork();
// 	if (pid == 0)
// 	{
// 		execve()
// 	}
// }