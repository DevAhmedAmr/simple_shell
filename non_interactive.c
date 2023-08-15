#include "main.h"
void print_arg_non_int(char **args);
// char ***tokenize_non_int(char **cmd, char ***args)
// {
// 	int i = 0;
// 	int malloc_count = 1;
// 	char ***token_arr = malloc(sizeof(char **) * malloc_count);
// 	char **token = NULL;

// 	non_int(cmd, args);

// 	printf("here\n");

// 	while ((*args)[i] != NULL)
// 	{
// 		char ***tmp;

// 		token = tokenize_string((*args)[i], " \n");
// 		token_arr[i] = token;
// 		malloc_count++;
// 		i++;
// 		/**r*/

// 		tmp = realloc(token_arr, sizeof(char **) * malloc_count);

// 		if (tmp == NULL)
// 		{
// 			free_3d_arr(token_arr);
// 			free(cmd);
// 			free_double_arr(*args);
// 			return NULL;
// 		}

// 		token_arr = tmp;
// 	}
// 	token_arr[i] = NULL;

// 	return token_arr;
// }

void non_interactive(char **cmd, char ***args)
{
	size_t read;
	size_t size;
	int i = 0;

	while ((read = getline(cmd, &size, stdin)) != -1)
	{

		*args = tokenize_string(*cmd, " \n");

		print_arg_non_int(*args);
		free_double_arr(*args);
		i++;
	}
}
void print_arg_non_int(char **args)
{
	for (size_t j = 0; args[j] != NULL; j++)
	{
		if (j == 0)
			printf("argv :: ");

		printf("%s ", args[j]);

		if (args[j + 1] != NULL)
		{
			printf(",");
		}
	}
	printf("\n");
	// fflush(stdout);
}