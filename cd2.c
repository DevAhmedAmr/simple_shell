#include "main.h"
/**
 * cd - function that handles changing directory
 * @args: a pointer to the str input splitted to 2d array (tokens)
 * Return: (1)  , or (-1) if malloc failed
 */
int cd(char **args)
{
	char *PWD = (_getnEnv("PWD", 3));

	if (PWD == NULL)
		return (1);

	if (args[1] == NULL)
		return (cd_Home_path(PWD));

	if (!strcmp("-", args[1]) || !strcmp("-\n", args[1]))
		return (cd_to_OLDPWD(PWD));

	update_OLDPWD(PWD);
	change_dir(args[1]);

	return (1);
}
