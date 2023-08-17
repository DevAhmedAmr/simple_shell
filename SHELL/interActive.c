#include "main.h"
#include <stddef.h>



int inter_Active(char **argv, char **cmd)
{

	size_t cmdLen = 0;



	int getLin = getline(cmd, &cmdLen, stdin);
	if (getLin == -1)
			return (getLin);


	if (strcmp(*cmd, "exit\n")== 0  )
	{
		printf("interAct exit.c:23\n");

		free(*cmd);
		free(*argv);
		exit(0);
	}
	free(*argv);
	argv = tokenize(*cmd, " \n");
	//  prin_argv( *argv);
	for (size_t i = 0; argv[i]; i++ )
		 executeCommand(argv[i], argv);




	return (0);
}
