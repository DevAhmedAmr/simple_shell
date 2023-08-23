#include "main.h"
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
