#ifndef MAIN_H
#define MAIN_H

/* Hraders*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Functions Prototype*/

/* String.c */
int Putchar(char c);
int printTS( char* s, size_t len);
char *StrCopy(char *dest, char *src);
int Strcmp(char *s1, char *s2);
size_t prin_argv(char **argv);
void printargv(char **argv);
int printPathAtt(char** PathArr, char** argv);
size_t printDblArr(char** DblArr, size_t NullTrm);


/**/


int inter_Active( char **cmd, char **PathArr, char **argv);
int non_Inter_Active(char *cmd,char **PathArr,char **argv);

char  **tokenize(char *cmd, char*  delim);
char **TokenEnvfPath();

int executeCommand(char *command, char **argv);

 char *SearchIntEnv(char *startWith);

/*memory management*/
size_t freeDoubleArray(char **argv);

/* befExe*/
char *isExecuteable(char **PathArr ,char **argv);
char *mrgCmdAndPath(char *currPath ,char *cmdName);
void EXEECUTE(char **PathArr, char **argv);



#endif
