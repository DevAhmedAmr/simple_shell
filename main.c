#include "main.h"
int main(void)
{
	char *cmd = NULL, **args = NULL;
	int interActive = isatty(STDIN_FILENO);

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

			if (args[0] != NULL)
				tryExecuteCommand(args[0], args);

			/*free mem*/

			free(cmd);
			free_double_arr(args);
		}
	return 0;
}

void print3d_arr(char ***threeD_arr)
{
	size_t i;

	for (i = 0; threeD_arr[i] != NULL; i++)
	{
		char **token = threeD_arr[i];
		size_t j;

		for (j = 0; token[j] != NULL; j++)
		{
			printf(" %s", token[j]);

			if (token[j + 1] != NULL)

				putchar(',');
		}
		putchar('\n');
	}
}

char *check_is_executable_in_paths(char *input)
{
	int i = 0, is_executable;
	char *path = _getEnv("PATH=");
	char *pathCpy, **pathsArray;

	if ((access(input, X_OK)) == 0)
	{
		pathCpy = strdup(input);
		return pathCpy;
	}

	if (path == NULL)
	{
		perror(path);
		/* exit(127);*/
		return NULL;
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
			return NULL;
		}

		if ((is_executable = access(pathsArray[i], X_OK)) == 0)
		{
			char *found_path = strdup(pathsArray[i]);
			free_double_arr(pathsArray);
			free(pathCpy);
			return found_path;
		}
		i++;
	}

	free_double_arr(pathsArray);
	free(pathCpy);

	if (is_executable != 0)
		perror(input);

	return NULL;
}
void printArgs(char **args)
{
	size_t j;
	for (j = 0; args[j] != NULL; j++)
	{
		printf("argv :: %s\n", args[j]);
	}
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

int tryExecuteCommand(char *input, char **args)
{
	char *exc_path;
	int execve_status = 0;

	if (input == NULL)
		return -1;

	if ((exc_path = check_is_executable_in_paths(input)) != NULL)
	{
		execve_status = ExecuteCommand(exc_path, args);
		free(exc_path);
	}
	return execve_status;
}
int ExecuteCommand(char *input, char **args)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		return -1;
	}

	if (pid == 0)
	{
		if (execve(input, args, environ) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*parent pros*/
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			return exit_status;
		}
		else
			return -1;
	}
	return 0;
}
