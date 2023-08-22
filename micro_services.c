#include "main.h"
char *_getEnv(char *env)
{
	char **s = environ;

	while (*s != NULL)
	{
		if (strncmp(*s, env, 5) == 0)
			return *s;

		s++;
	}

	return NULL;
}
void print3d_arr(char ***threeD_arr)
{
	size_t i;

	for (i = 0; threeD_arr[i] != NULL; i++)
	{
		char **token = threeD_arr[i];
		size_t j;

		for (j = 0; token[j] != NULL; j++)
		{
			printf(" %s", token[j]);

			if (token[j + 1] != NULL)

				putchar(',');
		}
		putchar('\n');
	}
}
void print_2d_arr(char **args)
{
	size_t j;

	for (j = 0; args[j] != NULL; j++)
		printf("%s\n", args[j]);
}