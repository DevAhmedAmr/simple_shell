#include "main.h"
/**
 * main - a entry point to a program the mimics the shell code
 * interpreter
 *
 * @parameters:
 * @argc: number of command lines args
 * @argv: command line args
 *
 * Return: if success or a error number status otherwise
 */
int main(int argc, char **argv)
{
	char *cmd = NULL, **args = NULL;
	int interActive = isatty(STDIN_FILENO), status = 0, i = 1;
	(void)argc;
	if (!interActive)
	{
		status = non_interactive(&cmd, &args, argv[0]);
		free(cmd);
		return (status);
	}
	else
		while (1)
		{

			write(STDIN_FILENO, "$ ", 2);
			args = malloc(sizeof(char *) * 50);

			if (interactive_mode(&cmd, &args) == EOF)
			{
				write(STDIN_FILENO, "\n", 1);

				FREE_ARGS_AND_CMD;
				exit(status);
			}

			if (builtIns(cmd, args, status))
			{
				FREE_2D_ARGS_AND_CMD;
				i++;
				continue;
			}

			if (args[0] != NULL)
				status = tryExecuteCommand(args[0], args, i, argv[0]);

			FREE_2D_ARGS_AND_CMD;
			i++;
		}
	return (status);
}

/**
 *  builtIns - function that handles built ins functions
 * like exit , env , cd ,etc ..
 *
 * @parameters:
 * @cmd: command line input to be checked
 * @args: array of strings that contain command line but splitted
 * @status: error stats , success if 0 otherwise an error occurred
 *
 * Return: 0  if the command line doesn't contain built in
 * requests otherwise it will return 1
 */

int builtIns(char *cmd, char **args, int status)
{

	if (!strcmp(cmd, "exit") || !strcmp(cmd, "exit\n"))
	{
		free(cmd);
		free_double_arr(&args);
		exit(status);
	}
	else if (!strcmp(cmd, "env\n") || !strcmp(cmd, "env"))
	{
		print_2d_arr(environ);
		return (1);
	}
	return (0);
}

/*1 - changed path to path1 and input / bin / ls success */
/*2 - removed path input ls fail*/
