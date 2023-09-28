#include "main.h"
int change_dir(char *path)
{
	char buff[100];

	chdir(path);
	getcwd(buff, 100);
	setenv("PWD", buff, 1);
	return 0;
}
