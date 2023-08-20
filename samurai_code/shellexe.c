#include "main.h"
#include <string.h>

extern char **environ;
/*
search
acess();
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int Execvp(const char *file, char *const argv[])
{
    char *path = SearchIntEnv("PATH=");
    if (path == NULL) {
        // If PATH is not set, we try to execute the file directly.
        execv(file, argv);
        perror("execv");
        return -1;
    }

    char *path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("strdup");
        return -1;
    }

    char *dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        // Allocate enough space for the directory, the file, a slash, and a null terminator.
        char *full_path = malloc(strlen(dir) + strlen(file) + 2);
        if (full_path == NULL)
        {
            perror("malloc");
            free(path_copy);
            return -1;
        }

        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, file);

        execv(full_path, argv);
        // If execv returns, it means it failed. We free the full path and try the next directory.
        free(full_path);

        dir = strtok(NULL, ":");
    }

    free(path_copy);
    // If we've tried every directory and execv failed each time, we return an error.
    perror("execv");
    return -1;
}

int executeCommand(char *command, char **argv)
{
	// if (!strcmp(command , "env"))
	// 	 return(0);
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0) {
		// Child process
		if (Execvp(command, argv) == -1) {
			printf("Command \" %s \" not found \n",command);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) {
		// Parent process
		waitpid(pid, &status, 0);
	} else {
		// Fork failed
		perror("sorry something went rong :)");
		exit(EXIT_FAILURE);
	}

	return 0;
}
 /*
int executeCommand(char *command, char **argv)

{
	printf("cmmmand => %s\n",command);
	printf("%s",command)

	for (int i = 0; argv[i]; i++)
		printf("argv[%s]\n", argv[i]);

	pid_t pid;
	int status;
	// pid = fork();
	char *x[] = {"-la",">","tst.txt"};



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

}
*/