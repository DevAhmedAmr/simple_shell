#include <stdio.h>
#include <string.h>
#include <stdlib.h>
size_t keylen(char *key);
void function(char *str)
{
	strcpy(str, "a");
	str = "ahmed";
}
int main()
{
	char *str = strdup("ahmed=gamedGamoda");
	size_t key_len = keylen(str);

	printf("%int\n", strncmp("A", "AA", 2));

	free(str);
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