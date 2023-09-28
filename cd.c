#include "main.h"
int change_dir(char *path)
{
	char buff[100];

	;
	if (chdir(path) == -1)
	{
		fprintf(stderr, "cd: no such file or directory: %s\n", path);
		return (-1);
	}

	getcwd(buff, 100);
	setenv("PWD", buff, 1);
	return (0);
}
