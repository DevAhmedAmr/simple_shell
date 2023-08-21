#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int non_Inter_Active(char *cmd,char **PathArr,char **argv)
{
	size_t cmdLn;
	int gtLin;
		// fprintf(stderr, "%s :  %s: not found\n", cmd ,argv[0]);
		if (!cmd)
			printf("cmd");
		if (!argv)
			printf("argv");

	int i = 0;
	cmd = malloc(50);
	while (gtLin != -1)
	{
		gtLin = getline(&cmd, &cmdLn,stdin);
		argv =  tokenize(cmd," \n");
		if (!argv || !cmd)
			{
				fprintf(stderr, "\033[1;31m_argv nonInterActive.c:20_\033[0m\n ");

			}

		EXEECUTE(PathArr, argv);

		printDblArr(argv, 0);

		freeDoubleArray(argv);
		i++;

	}

	return (0);

}


