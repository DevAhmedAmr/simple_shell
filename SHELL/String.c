#include "main.h"
#include <stddef.h>
/**
 * _strcmp - compare strings
 * @s1: type char*
 * @s2: type char*
 *
 * Return: (0) if both are equal , postive if the dont
 */
int Strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)

		return (*s1 - *s2);
	else
		return (0);
}
/**
 * StrCopy - copies a strings using pointers
 *
 * @src:source string
 *
 * @dest:destination string
 *
 * Return: the  value of destnation string
 *
 */
char *StrCopy(char *dest, char *src)

{
	 long long  i ;

	for (i = 0; i <= strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/*  print function*/
/**
 * Putchar - prints char c to stdout
 * @c : the character to print
 * Return: 0 on Sucsess , any integer else for failed
 */

int Putchar(char c)
{
	write(1, &c, sizeof(c));
	return (0);
}
/**
 * @brief
 *
 * @param s
 * @param len
 * @return int
 */
int printTS( char* s, size_t len)
{
	size_t i= 0;
	for (; i < len; i++)
	{
		Putchar(s[i]);
		if(s[i] == '\0')
			Putchar(10);
	}
	Putchar(10);
return (0);

}
/**
 * @brief
 *
 * @param argv
 * @return size_t
 */
size_t prin_argv(char **argv)
{
	size_t i,j;
	for (i = 0; argv[i]; i++)
		for (j = 0; argv[i][j] != '\0'; j++)
			putchar(argv[i][j]);
	return (j);
}




/**
*/

/*
void printEnv()
{
	for (size_t i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}


int printPathAtt(char** PathArr, char** argv)
{

	TokenEnvfPath(PathArr, argv);

	if (!strcmp(argv[0], "env") && argv[1] == NULL)
		for (size_t i = 0; PathArr[i]; i++)
			printf("[%zu] =>  %s\n", i, PathArr[i]);
	else if ((!strcmp(argv[0], "env")) && (!strcmp(argv[1], ".exe")))
		for (size_t i = 0; PathArr[i]; i++)
		{
			printf("[%zu] =>  %s\n", i, PathArr[i]);
			printf("access[%zu] =>  %i\n", i, access(PathArr[i], X_OK));
		}
		freeDoubleArray(PathArr);

	// printf("1 %s 2  %s\n" ,argv[0],argv[1]);

}
*/
size_t printDblArr(char** DblArr, size_t NullTrm)
{
	size_t i, j;
	if (NullTrm >  0)
		j = NullTrm;
	else if (NullTrm == 0)
		for (j = 0; DblArr[j]; j++)
			if (DblArr[j] == NULL)
				return (0);

	for (i = 0; i < j; i++)
		printf("[%zu] - %s  \n", i,DblArr[i]);

	return (i);
}