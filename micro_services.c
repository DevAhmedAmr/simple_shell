#include "main.h"
char *_getEnv(char *env)
{
	char **s = environ;

	while (*s != NULL)
	{
		if (strncmp(*s, env, 4) == 0)
			return *s;

		s++;
	}

	return NULL;
}
