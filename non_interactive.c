#include "main.h"
void print_arg_non_int(char **args);
int non_interactive(char **cmd, char ***args)
{
	int read;
	size_t size;
	int i = 0, execve_status;

	while ((read = getline(cmd, &size, stdin)) != -1)
	{
		if (!strcmp(*cmd, "exit\n") || !strcmp(*cmd, "exit"))
		{
			if (execve_status == 2)
				exit(2);

			exit(0);
		}

		*args = tokenize_string(*cmd, " \n");

		if (args[0] != NULL)
			execve_status = tryExecuteCommand((*args)[0], *args);

		free_double_arr(*args);

		i++;
	}
	return execve_status;
}
void print_arg_non_int(char **args)
{
	size_t j;
	for (j = 0; args[j] != NULL; j++)
	{
		if (j == 0)
			printf("argv :: ");

		printf("%s ", args[j]);

		if (args[j + 1] != NULL)
		{
			printf(",");
		}
	}
	printf("\n");
}