#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inter_Active(char **cmd, char **PathArr, char **argv)
{

	size_t cmdLen = 0;



	int getLin = getline(cmd, &cmdLen, stdin);
	if (getLin == -1)
	{
    free(*cmd);
	 if (argv)
			freeDoubleArray(argv);
	 if (PathArr)
			freeDoubleArray(PathArr);
	 // free(*argv);
	  return (getLin);
	}

	if (strcmp(*cmd, "exit\n") == 0) {
	 // printf("interAct exit.c:23\n");
  if (cmd)
	  free(*cmd);
	if (argv)
			freeDoubleArray(argv);
	if (PathArr)
			freeDoubleArray(PathArr);
	 // free(*argv);
	 exit(0);
	}
	// free(*argv);



	argv = tokenize(*cmd, " \n");

	if (argv == NULL || argv[0] == NULL) {
		// continue to the next iteration of the loop
		return 0; // or continue; if you're in a loop
	}


// printf("hay hay hay Path Executable Test %s\n\n\n\n",isExecuteable(PathArr ,argv));
		EXEECUTE(PathArr, argv);

	// printf("\n\n\n interactive.c:27 argv[0]%s \n\n\n ",argv[0]);
	//	prin_argv( *argv);

	//	executeCommand(*cmd, argv);
/*
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
	*/
	// executeCommand(*cmd, argv);

	return (0);
}
