#include "main.h"
int printEnvPath(char *input);
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

			tokenize_interactive_mode(&cmd, &args);

			printArgs(args);

			if (args[0] != NULL)
				printEnvPath(args[0]);

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

int printEnvPath(char *input)
{
	int i = 0;
	char *path = _getEnv("PATH=");
	char *pathCpy;
	if (path == NULL)
		return -1;

	pathCpy = strdup(path);

	char **ListOFpaths = tokenize_string(pathCpy, ":=");

	while (ListOFpaths[i] != NULL)
	{
		if (append_to_path(&ListOFpaths[i], input) == -1)
		{
			free_double_arr(ListOFpaths);
			free(pathCpy);
			return -1;
		}

		i++;
	}

	free_double_arr(ListOFpaths);
	free(pathCpy);

	return 0;
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
	char *tmp = realloc(*path, sizeof(char) * (path_len + input_len + 3)); // +2 for the slash and null terminator

	if (tmp == NULL)
	{
		fprintf(stderr, "Memory reallocation failed.\n");

		return -1; // return NULL on failure
	}

	*path = tmp;

	strcat(*path, "/");
	strcat(*path, input);

	printf("%s\n\n", *path);

	// return the newly allocated path
	return 0;
}
