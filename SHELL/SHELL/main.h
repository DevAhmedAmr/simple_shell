#ifndef MAIN_H
#define MAIN_H

/* Hraders*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Functions Prototype*/

/* String.c */
int Putchar(char c);
int printTS( char* s, size_t len);
char *StrCopy(char *dest, char *src);
int Strcmp(char *s1, char *s2);
size_t prin_argv(char **argv);


/**/
int inter_Active(char **argv, char **cmd);


char  **tokenize(char *cmd, char*  delim);

int executeCommand(char *command, char **argv);



/*memory management*/
size_t free_argv(char **argv);


#endif
