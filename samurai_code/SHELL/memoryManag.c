#include "main.h"
size_t free_argv(char **argv)
{
	size_t i;
	for (i = 0; argv[i] ; i++)
		free(argv[i]);
}
