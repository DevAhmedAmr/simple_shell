#include "main.h"
void print_arg_non_int(char **args);
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

		/*if (!strcmp(*cmd, "env\n"))*/
		/*	{*/
		/*print_2d_arr(environ);*/
		/*return 0;*/
		/*}*/
		builtIns(*cmd, *args, status);
		*args = tokenize_string(*cmd, " \n");

		if (args[0] != NULL)
			status = tryExecuteCommand((*args)[0], *args, i, app_name);

		free_double_arr(*args);

		i++;
	}
	return status;
}
void print_arg_non_int(char **args)
{
	size_t j;
	for (j = 0; args[j] != NULL; j++)
	{
		if (j == 0)
			printf("argv :: ");

		printf("%s ", args[j]);

		if (args[j + 1] != NULL)
		{
			printf(",");
		}
	}
	printf("\n");
}