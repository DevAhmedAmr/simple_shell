#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  *isNullTrm(char **arr)
{
	size_t i;
	for (i = 0; arr[i] ; i++ )
		if (!arr[i +1])
				return ("ARRAY NULL YERMINATED");

return (0);
}

char *mrgCmdAndPath(char *currPath ,char *cmdName)
{

	size_t i;
	char *mergedPath;

	mergedPath =malloc( (strlen(cmdName) + strlen(currPath) ) * sizeof(char) );
	if (!mergedPath)
		{
			fprintf(stderr, "mergedPath Allocation Failer.c %d",__LINE__);
			return (NULL);
		}
	strcat(mergedPath, currPath);
	strcat(mergedPath,"/");

	strcat(mergedPath,cmdName);
	if (access(mergedPath , X_OK)  == 0)
			return (mergedPath);
	else
		{
			free(mergedPath);
			mergedPath = NULL;
			printf("%d_",__LINE__);

		}

	// printf("\n>>>>>>>mergedPath<<<<< %s \n",mergedPath);

	return (0);

}
char *isExecuteable(char **PathArr ,char **argv)
{
	size_t i;
	char* isPathExe;
	for (i = 0; PathArr[i]; i++)

			{
				char *isPathExe = mrgCmdAndPath(PathArr[i], argv[0]);
				if (isPathExe)
					return (isPathExe);
			}

	return (0);
}

