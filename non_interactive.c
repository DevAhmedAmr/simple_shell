#include "main.h"
extern int counter;
/**
 * non_interactive - run the shell in interactive mode
 *
 * @cmd: command
 * @args: array of argument that hve ben tokenize
 * @app_name: the app exe name (argv[0])
 * Return:the getline function return (-1) indicate error or  file end
 */

int non_interactive(char **cmd, char ***args)
{
	int read;
	size_t size;
	int builtIns_status;
	int status = 0;

	while ((read = getline(cmd, &size, stdin)) != -1)
	{

		/*if (!strcmp(*cmd, "exit\n") || !strcmp(*cmd, "exit"))*/
		/*{*/
		/*if (status == 2)*/
		/*exit(2);*/
		/*	exit(status);*/
		/*	}*/
		*args = tokenize_string(*cmd, " \n");

		builtIns_status = builtIns(*cmd, *args, status);

		if (builtIns_status)
		{
			free_double_arr(args);
			free(*cmd);
			*cmd = NULL;
			counter++;
			return status;
		}

		if (args[0] != NULL)
			status = tryExecuteCommand((*args)[0], *args);

		free_double_arr(args);

		counter++;
	}
	return (status);
}
