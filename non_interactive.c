#include "main.h"

#include "main.h"
#include "main.h"
/**
 * interactive_mode - run the shell in interactive mode
 *
 * @cmd: command
 * @args: array of ragument that hve ben tokenize
 * Return:the gitline function return (-1) indecats eeeor or  file end
 */

int interactive_mode(char **cmd, char ***args)
{
	size_t size = 0;

	int read = getline(cmd, &size, stdin);

	if (read == -1)
		return (EOF);

	/*if (!strcmp(*cmd, "exit\n"))*/
	/*{*/
	/*free(*cmd);*/
	/*free(*args);*/
	/*exit(0);*/
	/*}*/

	/*free the old args value before reassigning it*/
	free(*args);
	*args = tokenize_string(*cmd, " \n");

	return (0);
}
