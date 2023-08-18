#include "main.h"

extern char **environ;

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
    printf("cmmmand => %s\n", command);

    for (int i = 0; argv[i]; i++)
        printf("argv[%s]\n", argv[i]);

    pid_t pid;
    int status;
    pid = fork();

    if (pid == 0)
    {
        execve(command, argv, NULL);

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
}
