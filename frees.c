#include "main.h"
#include "main.h"
/**
 * free_double_arr - free double arr
 * @args: double array
 */

void free_double_arr(char ***args)
{
	int j;

	if (*args == NULL)
		return;

	for (j = 0; (*args)[j] != NULL; j++)
	{
		free((*args)[j]);
		(*args)[j] = NULL;
	}

	free(*args);
	*args = NULL;
}

/**
 * free_3d_arr - free 3d arr
 * @args: 3d array
 */
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
