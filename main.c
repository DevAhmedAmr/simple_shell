#include "main.h"
int Exit_fun(char *cmd, char **args, int *status);
int positive_parseInt(char *str);
char *app_name;
int counter = 1;
/**
 * main - a entry point to a program that mimics the shell code
 * interpreter
 *
 * @parameters:
 * @argc: number of command lines args
 * @argv: command line args
 *
 * Return: (0) if success or a error number status
 */
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

			if (builtIns(cmd, args, &status))
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

int builtIns(char *cmd, char **args, int *status)
{

	if (args[0] != NULL && Exit_fun(cmd, args, status) == 1)
		return (1);

	else if (!strcmp(cmd, "env\n") || !strcmp(cmd, "env"))
	{
		print_2d_arr(environ);
		return (1);
	}
	else if (!strcmp("setenv\n", cmd) || !strcmp("setenv", cmd))
	{
		set_env(args);
		return (1);
	}
	else if (!strcmp("unsetenv\n", cmd) || !strcmp("unsetenv", cmd))
	{
		unset_env(args);
		return (1);
	}
	return (0);
}

/**
 * Exit_fun - function that handles the input if its' exit
 *
 * Description: function that handles the cmd
 *  if its 'exit' with or without arguments
 *
 * @cmd: command line input argument
 * @args: command line input argument splitted into an array
 * @status: the last operation status in the entire app
 * Return: '1' if the exit argument if not valid
 *  '0'  if the command line arg is not a built in arg
 */
int Exit_fun(char *cmd, char **args, int *status)
{
	int isExit = (!strcmp("exit\n", cmd) || !strcmp("exit", cmd));
	int custom_exit_status = positive_parseInt(args[1]);
	/*printf("%i %i %i\n", isExit, args[1] != NULL, custom_exit_status > -1);*/

	if (isExit && args[1] == NULL)
	{
		free(cmd);
		free_double_arr(&args);
		exit(*status);
	}

	else if (isExit && args[1] != NULL && custom_exit_status > -1)
	{
		free(cmd);
		free_double_arr(&args);
		exit(custom_exit_status);
	}
	else if (isExit && args[1] != NULL)
	{
		*status = 2;
		fprintf(stderr, "%s: %i: %s: Illegal number: %s\n",
				app_name, counter, cmd, args[1]);
		return (1);
	}
	return (0);
}
/**
 * positive_parseInt -a function that parse string into positive int
 *
 * Description: a function that parse string into an integer but
 * it only supports positive numbers
 * @str: string to be parsed to int
 *
 * Return: -1 if the string is not a positive number (on failure)
 * and the number if success
 * @retval
 */

int positive_parseInt(char *str)
{
	int result = 0;
	int i = 0;

	if (str == NULL)
		return (-1);

	while (str[i] != '\0')
	{
		char parsing = (int)str[i] - 48;

		if (parsing <= 9 && parsing >= 0)
		{
			result *= 10;
			result += parsing;
		}
		else
			return (-1);

		i++;
	}
	return (result);
}
