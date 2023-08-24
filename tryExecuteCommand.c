#include "main.h"
/**
 * tryExecuteCommand - function that tries to execute the command line input
 * Description: first it check if it executable or not .
 * then if it executable it will execute it , if not it will return 127
 *
 * @input: input  first token or element of a 2d array
 * of the command line argument
 *
 * @args: 2d array of the command line argument splitted
 *
 * @app_name: the program or the app name that we fetch form argv[0]
 *
 * @command_count: counter for the loop in the interactive mode
 * that we use in the massage error if the path is not found
 *
 * Return: 0 if success, the exit status of the child ,
 * or 127 if didn't find the command in the env paths
 */

int tryExecuteCommand(char *input, char **args,
					  int command_count, char *app_name)
{
	char *exc_path;
	int execve_status = 0;

	if (input == NULL)
		return (0);

	exc_path = is_executable_in_env_paths(input, command_count, app_name);

	if (exc_path)
	{
		execve_status = ExecuteCommand(exc_path, args);
		free(exc_path);
	}
	else
		return (127);

	return (execve_status);
}
