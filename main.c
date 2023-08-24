#include "main.h"
int Exit_fun(char *cmd, char **args, int status);
int stringToInt(char *str);
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
char *app_name;
int counter = 1;
int main(int argc, char **argv)
{
	char *cmd = NULL, **args = NULL;
	int interActive = isatty(STDIN_FILENO), status = 0;
	app_name = argv[0];

	(void)argc;
	if (!interActive)
	{
		status = non_interactive(&cmd, &args);
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
				counter++;
				continue;
			}

			if (args[0] != NULL)
				status = tryExecuteCommand(args[0], args);

			FREE_2D_ARGS_AND_CMD;
			counter++;
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

	if (args[0] != NULL && Exit_fun(cmd, args, status) == 1)
		return 1;

	else if (!strcmp(cmd, "env\n") || !strcmp(cmd, "env"))
	{
		printf("\n\n%s\n\n", cmd);

		print_2d_arr(environ);
		return (1);
	}
	return (0);
}
int Exit_fun(char *cmd, char **args, int status)
{
	int isExit = (!strcmp("exit\n", cmd) || !strcmp("exit", cmd));
	int custom_exit_status = stringToInt(args[1]);
	/*printf("%i %i %i\n", isExit, args[1] != NULL, custom_exit_status > -1);*/

	if (isExit && args[1] == NULL)
	{
		free(cmd);
		free_double_arr(&args);
		exit(status);
	}

	else if (isExit && args[1] != NULL && custom_exit_status > -1)
	{
		free(cmd);
		free_double_arr(&args);
		exit(custom_exit_status);
	}
	else if (isExit && args[1] != NULL)
	{
		fprintf(stderr, "%s: %i: %s: Illegal number: %s\n",
				app_name, counter, cmd, args[1]);
		return (1);
	}
	return (0);
}
/*1 - changed path to path1 and input / bin / ls success */
/*2 - removed path input ls fail*/
int stringToInt(char *str)
{
	int result = 0;
	int i = 0;

	if (str == NULL)
		return -1;

	while (str[i] != '\0')
	{

		char parsing = (int)str[i] - 48;
		if (parsing <= 9 && parsing >= 0)
		{
			result *= 10;
			result += parsing;
		}
		else
		{
			return -1;
		}
		i++;
	}
	return result;
}
