#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

 char *SearchIntEnv(char *startWith)
{
	char **s = environ;

	for (; *s; s++ )
	/* && s[i][5] != '\0' && s[i][5] != ' ' */
		if (!strncmp(startWith, *s, 5 ) )
			return (*s);

return (NULL);
}


char *cmdExeCheck(char *command)
{
	int arrItor ,acessRes;

	char *envPaht = GetEnv("PATH="),*envPathCopy,
	**pathArray;
	/*why PATH= not just PATH GetEnv Chaeck first 4 chars*/
		if ((access(command, X_OK))  == 0)
		{
			envPathCopy = strdup(command);
			return (envPathCopy);
		}
		/* chaeck for path should done before access "executabilty"*/
		if (envPaht == NULL)
			{
				perror(envPaht);
				return (NULL);
			}
// .....
}
int appendTo( char *envPath, char *command)
{
	int comdLen =(int)strlen(command);
}