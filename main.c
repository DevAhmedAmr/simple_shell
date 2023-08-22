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

			if (builtIns(cmd, args, status))
			{
				i++;
				continue;
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
int builtIns(char *cmd, char **args, int status)
{
	if (!strcmp(cmd, "exit"))
	{
		free(cmd);
		free(args);
		exit(status);
	}
	else if (!strcmp(cmd, "env\n"))
	{
		print_2d_arr(environ);
		free(cmd);
		free_double_arr(args);
		return 1;
	}
	return 0;
}

/*1 - changed path to path1 and input / bin / ls success */
/*2 - removed path input ls fail*/
