#include "main.h"
/**
 * non_interactive - run the shell in interactive mode
 *
 * @cmd: command
 * @args: array of argument that hve ben tokenize
 * @app_name: the app exe name (argv[0])
 * Return:the getline function return (-1) indicate error or  file end
 */

int non_interactive(char **cmd, char ***args, char *app_name)
{
	int read;
	size_t size;
	int i = 1, status = 0;

	while ((read = getline(cmd, &size, stdin)) != -1)
	{

		/*if (!strcmp(*cmd, "exit\n") || !strcmp(*cmd, "exit"))*/
		/*{*/
		/*if (status == 2)*/
		/*exit(2);*/
		/*	exit(status);*/
		/*	}*/
		status = builtIns(*cmd, *args, status);

		if (status)
			return (0);

		*args = tokenize_string(*cmd, " \n");

		if (args[0] != NULL)
			status = tryExecuteCommand((*args)[0], *args, i, app_name);

		free_double_arr(args);

		i++;
	}
	return (status);
}
