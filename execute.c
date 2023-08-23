#include "main.h"
/**
 * ExecuteCommand - a function that takes  a string that represents
 * the complete path to the executable file that we want it to run.
 *  then execute it
 *
 * @params
 * @file_name : a string that represents the complete
 *  path to the executable file you want to run .
 *
 * @args: an array of string pointers, where each
 * string is one "argument" to the executable. By convention
 *
 * Return: 0 if success , -1 if fail
 */

int ExecuteCommand(char *file_name, char **args)
{

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(file_name, args, environ) == -1)
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

			return (exit_status);
		}
		else
			return (-1);
	}
	return (0);
}
