#include "main.h"

extern char **environ;
/*
search
acess();
*/
void printEnv()
{
    for (size_t i = 0; environ[i] != NULL; i++)
    {
        write(1, environ[i], strlen(environ[i]));
        write(1, "\n", 1);
    }
}
int executeCommand(char *command, char **argv)

{
    // printf("cmmmand => %s\n",command);
    // printf("%s",command)

	// for (int i = 0; argv[i]; i++)
		// printf("argv[%s]\n", argv[i]);

    pid_t pid;
    int status;
    // pid = fork();
    char *x[] = {"-la",">","tst.txt"};


    /*
execve("bin/ls", x, NULL) ;

    if (pid == 0)
    {

        if (execve(command, argv, NULL) == -1)
        {
            printf("'%s' : command not found\n", command);
            exit(EXIT_FAILURE);
        };
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    */
}
