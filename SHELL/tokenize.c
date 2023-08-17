#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  **tokenize(char *cmd, char*  delim)
{
	size_t TksNum = 0;
	char *token = NULL, **Tokens = NULL;

	token = strtok(cmd, delim);
	while (token)
	{
		Tokens = realloc(Tokens, sizeof(char *) * (TksNum + 1));

		if (!Tokens)
		{
			free_argv(Tokens);
			perror("tokenaize.c:21 realloc");
			return (NULL);
		}
	/* tokinize && Asign */
		Tokens[TksNum] = strdup(token);
		// printf("tenize.c:25 %s\n",Tokens[TksNum]);
		token = strtok(NULL, delim);
		TksNum++;
	}

		Tokens = realloc(Tokens, sizeof(char *) * (TksNum + 1));
		if (!Tokens)
		{
			free_argv(Tokens);
			perror("tokenaize.c:21 realloc");
			return (NULL);
		}

		Tokens[TksNum] = NULL;
			return (Tokens);
}


