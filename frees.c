#include "main.h"
void free_double_arr(char **args)
{
	int j;
	for (j = 0; args[j] != NULL; j++)
		free(args[j]);

	free(args);
}

void free_3d_arr(char ***args)
{
	int j, i;

	for (i = 0; args[i] != NULL; i++)
	{
		for (j = 0; args[i][j] != NULL; j++)
			free(args[i][j]);

		free(args[i]);
	}

	free(args);
}
