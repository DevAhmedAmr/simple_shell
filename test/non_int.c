#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

extern char **environ;

void env()
{
	for (size_t i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}
void execute(char *input, char **arr)
{
	pid_t pid;
	int status;
	pid = fork();

	if (pid == 0)
	{

		if (execve(input, arr, NULL) == -1)
		{
			printf("'%s' : command not found\n", input);
			exit(EXIT_FAILURE);
		};
	}
	else
	{
		waitpid(pid, &status, 1);
	}
}
int main()
{
	char *input = NULL;
	size_t size = 0;
	ssize_t x;
	pid_t pid;

	printc();
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{

			write(1, "$ ", 2);
			x = getline(&input, &size, stdin);
			input[x - 1] = '\0';
			if (strcmp(input, "env") == 0)
			{
				env();
			}
		}
	}
	else

		while ((x = getline(&input, &size, stdin)) != -1)
		{
			pid_t y = getpid();
			printf("$ , pid %i ", y);

			// fflush(stdout);

			// printf("$ ");
			// ls-a\n\n
			input[x - 1] = '\0';
			char *arr[2] = {input, NULL};
			execute(input, arr);
		}

	free(input);
	return 0;
}
