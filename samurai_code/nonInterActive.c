#include "main.h"
#include <stddef.h>
#include <stdio.h>
int non_Inter_Active(char *cmd, char **argv)
{
	size_t gtLin, cmdLn;
		// fprintf(stderr, "%s :  %s: not found\n", cmd ,argv[0]);
		if (!cmd)
			printf("cmd");
		if (!argv)
			printf("argv");

	int i = 0;
	while ((cmdLn = getline(&cmd, &cmdLn,stdin) != -1))
	{
	argv =  tokenize(cmd," \n");

	 executeCommand(cmd,  argv);
	printDblArr(argv, 0);
	freeDoubleArray(argv);
	i++;

	}

}


