#include "main.h"

int main(int argc, char **argv)
{
	char *cmd = NULL, **args = NULL;
	int interActive = isatty(STDIN_FILENO), status = 0, i = 1;
	(void)argc;
	if (!interActive)
	{
		status = non_interactive(&cmd, &args, argv[0]);
		free(cmd);
		return status;
	}
	else
		while (1)
		{

			write(STDIN_FILENO, "$ ", 2);

			args = malloc(sizeof(char *) * 50);

			if (interactive_mode(&cmd, &args) == EOF)
			{
				write(STDIN_FILENO, "\n", 1);
				free(args);
				free(cmd);
				exit(status);
			}

			if (args[0] != NULL)
				status = tryExecuteCommand(args[0], args, i, argv[0]);

			/*free mem*/

			free(cmd);
			free_double_arr(args);
			i++;
		}
	return status;
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
/*1 - changed path to path1 and input / bin / ls success */
/*2 - removed path input ls fail*/

char *check_is_executable_in_paths(char *input, int command_count, char *app_name)
{
	int i = 0, is_executable;
	int is_full_path = (input[0] == '.' || input[0] == '/');
	char *path = _getEnv("PATH=");
	char *pathCpy, **paths;

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

int tryExecuteCommand(char *input, char **args, int command_count, char *app_name)
{
	char *exc_path;
	int execve_status = 0;

	if (input == NULL)
		return 0;

	if ((exc_path = check_is_executable_in_paths(input, command_count, app_name)) != NULL)
	{
		execve_status = ExecuteCommand(exc_path, args);
		free(exc_path);
	}
	else
		return (127);

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
			exit(EXIT_FAILURE);
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
