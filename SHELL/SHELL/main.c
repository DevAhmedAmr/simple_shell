#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int interActicve = isatty(STDIN_FILENO);
	char **argv = NULL, *cmd = NULL;


	/*isatty => 0 in case of interactive mode */
	if (!interActicve)
		{
			printf("File interActicve = %d\n",interActicve);

		}

	else
	{
		while(1)
		{
		write(STDIN_FILENO, "$ ", 2);

		argv = malloc(sizeof(char *) * 50);
		if (!argv)
			{
				perror("Main.c:29 Allocate Falier");
				return (0);
			}
		int exst = inter_Active(argv, &cmd);

		if (exst == -1)
		{
			write(STDIN_FILENO, " \n", 2);
			exit(127);
		}


		}

		free(cmd);
		free_argv(argv);
	}

	return (0);
}
