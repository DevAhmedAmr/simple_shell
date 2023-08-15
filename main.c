#include "main.h"
void printEnvPath();
void printArgs(char **args);
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

			printEnvPath();

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

void printEnvPath()
{
	int i;
	printf("%s\n", _getEnv("PATH="));

	char *path = _getEnv("PATH=");
	char *pathCpy = strdup(path);

	char **ListOFpaths = tokenize_string(pathCpy, ":=");
	i = 0;

	while (ListOFpaths[i] != NULL)
	{
		printf("env: {%s}\n", ListOFpaths[i]);
		i++;
	}
	free_double_arr(ListOFpaths);
	free(pathCpy);
}
void printArgs(char **args)
{
	for (size_t j = 0; args[j] != NULL; j++)
	{
		printf("argv :: %s\n", args[j]);
	}
}
int acsess(char *input, char *path)
{
	strcat(path, "/");
	strcat(path, input);
	printf("%s", path);
}

