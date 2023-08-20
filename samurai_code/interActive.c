#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int inter_Active(char **cmd, char **PathArr, char **argv)
{

  size_t cmdLen = 0;

  if (!*cmd)
    *cmd = " \n";

  int getLin = getline(cmd, &cmdLen, stdin);
  if (getLin == -1)
    return (getLin);

  if (strcmp(*cmd, "exit\n") == 0) {
    printf("interAct exit.c:23\n");

    free(*cmd);
    free(*argv);
    exit(0);
  }
  free(*argv);
  argv = tokenize(*cmd, " \n");
  //  prin_argv( *argv);

  //  executeCommand(*cmd, argv);

  if (!strcmp(*cmd, "env")) {
	printf("env :: ");
	if (PathArr && argv)
	{
    	// TokenEnvfPath(PathArr);
    	printDblArr(PathArr,0);
    	freeDoubleArray(PathArr);
	}
	else
	{
			perror("\033[1;31m- interActive.c:34 (null) :: ");
			if (argv)
				freeDoubleArray(argv);
			else
			 printf("\033[1;31m-argv-\033[0m\n");
			if(PathArr)
				freeDoubleArray(PathArr);
			else
			 printf("\033[1;31m-Patharr-\033[0m\n");

	}

  }
  executeCommand(*cmd, argv);

  return (0);
}
