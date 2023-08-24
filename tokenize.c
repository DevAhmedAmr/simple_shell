#include "main.h"
/**
 * tokenize_string - returns an 2d array of tokenized string
 *
 * @str: string to tokenze
 * @delim:tokenize delimeter
 * Return: (char**) 2d array of tokenized string
 */
char **tokenize_string(char *str, char *delim)
{
	char **tokenList = NULL;
	int i = 0;
	char *token = strtok(str, delim);

	while (token != NULL)
	{
		/* Reallocate memory to accommodate the new token*/
		tokenList = realloc(tokenList, sizeof(char *) * (i + 1));

		/* Check if memory allocation was successful*/
		if (tokenList == NULL)
		{
			free_double_arr(&tokenList);
			return (NULL);
		}

		tokenList[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	/* Allocate one more space for the NULL pointer at the end*/
	tokenList = realloc(tokenList, sizeof(char *) * (i + 1));
	tokenList[i] = NULL;

	return (tokenList);
}
