#include "main.h"
#include <stddef.h>
#include <stdio.h>
int nonInterActive(char *cmd, char **argv)
{
	size_t gtLin, cmdLn;
	int i = 0;
	while ((cmdLn = getline(&cmd, &cmdLn,stdin) != -1))
	{
	argv =  tokenize(cmd," \n");
	if (argv[i])
		 executeCommand(argv[0],  argv);
	free_argv(argv);
	i++;

	}

}


