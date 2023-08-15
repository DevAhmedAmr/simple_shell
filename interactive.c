#include "main.h"

void tokenize_interactive_mode(char **cmd, char ***args)
{
	size_t size = 0;

	int read = getline(cmd, &size, stdin);

	if (!strcmp(*cmd, "exit\n"))
	{
		free(*cmd);
		free(*args);
		exit(0);
	}

	/*free the old args value before reassigning it*/
	free(*args);
	*args = tokenize_string(*cmd, " \n");
}
