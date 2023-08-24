#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int interActicve = isatty(STDIN_FILENO);
	char** argv = NULL, **PathArr = TokenEnvfPath(), * cmd = " \n";




	/*isatty => 0 in case of interactive mode */
	if (!interActicve)
		{
		argv = malloc(sizeof(char *) * 50);
		cmd = malloc(sizeof(char ) * 50);

		non_Inter_Active(cmd,PathArr, argv);
			printf("main.c:25 non inter argv[0]=> %s ,cmd=> %s", argv[0], cmd);

		if (cmd)
		{
			free(cmd);
			printf("main.c:24 freed non inter  cmd");

		}
		if (argv)
		{
			freeDoubleArray(argv);
			fprintf(stderr, "non inter main.c:30   line: %d\n", __LINE__);

		}

		}

	else
	{
		while(1)
		{
			if (!cmd)
				cmd = " \n";
		write(STDIN_FILENO, "$ ", 2);

		argv =NULL;
		// if (!argv)
		// 	{
		// 		perror("Main.c:29 Allocate Falier");
		// 		return (0);
		// 	}
		int exst = inter_Active(&cmd, PathArr, argv);

		if (exst == -1)
		{
			write(STDIN_FILENO, " \n", 2);
			exit(127);
		}


		}

		free(cmd);
		freeDoubleArray(argv);
	}

	return (0);
}

/*
void printargv(char **argv)
{
	for (size_t j = 0; argv[j] != NULL; j++)
	{
		printf("%s\n", argv[j]);
	}
}
*/