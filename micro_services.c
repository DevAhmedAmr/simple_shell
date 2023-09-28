#include "main.h"

/**
 * _getEnv - get environment path
 *
 * @env:string "PATH="
 * Return: (char*) pointer to env path
 */
char *_getEnv(char *env)
{
	char **s = environ;

	while (*s != NULL)
	{
		if (strncmp(*s, env, 5) == 0)
			return (*s);

		s++;
	}

	return (NULL);
}
/**
 * print3d_arr - print 3d array
 * @threeD_arr:  3d array
 */
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
/**
 *  print_2d_arr - print 2d array
 * @args:  2d array
 */
void print_2d_arr(char **args)
{
	size_t j;

	for (j = 0; args[j] != NULL; j++)
		printf("%s\n", args[j]);
}

/**
 * _getnEnv - get environment path
 *
 * @env:string "PATH="
 * Return: (char*) pointer to env path
 */
char *_getnEnv(char *env, int n)
{
	char **s = environ;

	while (*s != NULL)
	{
		if (strncmp(*s, env, n) == 0)
			return (*s);

		s++;
	}

	return (NULL);
}