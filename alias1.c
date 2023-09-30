#include "main.h"
size_t keylen(char *key);
int initialize_Alias()
{
	alias = malloc(100 * sizeof(char));

	if (alias == NULL)
		return -1;

	alias[0] = NULL;

	return 0;
}

int add_alias(char *cmd)
{
	int i = 0;
	char *cmd_cpy = NULL;
	size_t key_length = 0;

	if (cmd == NULL)
		return -1;

	if (strchr(cmd, '=') == NULL || cmd[0] == '=')
		return (-1);

	cmd_cpy = add_quotations(cmd);
	key_length = keylen(cmd_cpy);

	for (; alias[i] != NULL; i++)
	{

		if (key_length == keylen(alias[i]) &&
			!strncmp(alias[i], cmd_cpy, key_length))
		{
			free(alias[i]);
			alias[i] = cmd_cpy;
			return 1;
		}
	}

	if (alias[i] == NULL)
	{
		alias[i] = cmd_cpy;
		alias[i + 1] = NULL;
	}
	return 1;
}

char *add_quotations(char *cmd)
{
	char *cmd_cpy = malloc(strlen(cmd) + 3 * sizeof(char));
	size_t i = 0, need_quotation = 0, len;

	strcpy(cmd_cpy, cmd);
	len = strlen(cmd_cpy);

	for (i = 0; i < len; i++)
	{
		if (cmd_cpy[i] == '=' && (cmd_cpy[i + 1] != 39 || cmd_cpy[len - 1] != 39))
		{
			need_quotation = 1;
			continue;
		}

		if (need_quotation == 1)
		{
			cmd_cpy = add_single_quotations_at(i, cmd_cpy);
			break;
		}
	};

	return cmd_cpy;
}

char *add_single_quotations_at(size_t pos, char *cmd)
{
	char tmp = cmd[pos], tmp2 = 0;
	size_t len = strlen(cmd), j = 0;

	cmd = realloc(cmd, (len + 3) * sizeof(char));

	if (cmd == NULL)
		return NULL;

	if (cmd[pos] == '\'')
	{
		if (cmd[len - 1] != '\'')
		{
			cmd[len] = 39;
			cmd[len + 1] = '\0';
		}
		return cmd;
	}

	cmd[pos] = 39;
	tmp2 = tmp;
	j = ++pos;

	for (; j < len + 1; j++)
	{
		tmp = cmd[j];
		cmd[j] = tmp2;
		tmp2 = tmp;
	}

	if (cmd[j - 1] != 39)
	{

		cmd[j] = 39;
		cmd[j + 1] = '\0';
	}
	else
		cmd[j] = '\0';

	return cmd;
}
size_t keylen(char *key)
{
	size_t i = 0;
	for (; i < strlen(key); i++)
	{
		if (key[i] == '=')
		{

			return i;
		}
	}
	return 0;
}