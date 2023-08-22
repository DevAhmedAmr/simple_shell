#include "main.h"
int tryExecuteCommand(char *input, char **args, int command_count, char *app_name)
{
	char *exc_path;
	int execve_status = 0;

	if (input == NULL)
		return 0;

	if ((exc_path = is_executable_in_env_paths(input, command_count, app_name)) != NULL)
	{
		execve_status = ExecuteCommand(exc_path, args);
		free(exc_path);
	}
	else
		return (127);

	return execve_status;
}