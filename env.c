#include "main.h"
int add_in_arr(char ***arr, char *str);

int set_env(char **input)
{
	char *env_var = NULL;
	char *value = NULL;
	char *var = NULL;

	if (double_arr_len(input) < 3)
		return 0;

	env_var = input[1];
	value = input[2];
	var = _getEnv(env_var);
	return setenv(env_var, value, 4);
}
int unset_env(char **input)
{
	char *env_var = NULL;

	if (double_arr_len(input) < 2)
		return 0;

	env_var = input[1];

	if (unsetenv(env_var) != 0)
		fprintf(stderr, "failed to unset\n");
	return -1;
}
/**
 * double_arr_len - function that get len of grids (2d array).
 *
 * @arr: array to calculate its len
 *
 * Return: len of arr
 */
int double_arr_len(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;
	return (i);
}