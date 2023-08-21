#include "main.h"

size_t freeDoubleArray(char **argv)
{
	size_t i, j;

	for (j = 0; argv[j]; j++)
			;
	for (i = 0; i < j; i++)
		free(argv[i]);

	free(argv);
	return (i);
}