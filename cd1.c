#include "main.h"
/**
 * change_dir - a helper function to "cd" that only
 * changes the current directory
 *
 * @path: a pointer to the new path that will be update to
 *
 * Return: (1) on succsess ,  (-1) if malloc failed or  the path doesn't exist
 */
int change_dir(char *path)
{
	char buff[100];

	if (chdir(path) == -1)
	{
		fprintf(stderr, "%s: %i: cd: can't cd to %s\n", app_name, counter, path);
		return (-1);
	}

	getcwd(buff, 100);
	setenv("PWD", buff, 1);
	return (0);
}
/**
 * update_OLDPWD - a helper function to "cd" that only set or
 * update the OLDPWD environment variable to the current PWD
 *
 * @old_pwd_path: a pointer to the new (OLDPWD) env value
 * that will be updated to
 *
 * Return: (1) on succsess ,  (-1) if malloc failed or  the path doesn't exist
 */
int update_OLDPWD(char *PWD)
{
	char *PWD_cpy = strdup(PWD);
	char **PWD_arr;

	if (PWD_cpy == NULL)
		return (1);

	PWD_arr = tokenize_string(PWD_cpy, "=");

	if (PWD_arr == NULL)
		return (-1);

	setenv("OLDPWD", PWD_arr[1], 1);

	free(PWD_cpy);
	free_double_arr(&PWD_arr);

	return (1);
}
/**
 * handling_NULL_OLDPWD - a helper function to "cd" that only
 * handel if the OLDPWD  is not exist
 *
 * Description: function that handel if the OLDPWD  doesn't exist
 * by printing the current PWD instead of OLDPWD
 *
 * @PWD: a pointer to PWD
 *
 * Return: (1) on succsess ,  (-1) if malloc failed or  the path doesn't exist
 */
int handling_NULL_OLDPWD(char *PWD)
{
	char *PWD_cpy = malloc(strlen(PWD) + 2 * sizeof(char));

	strcpy(PWD_cpy, PWD);

	if (!PWD_cpy)
		return (1);

	strcat(PWD_cpy, "\n");
	print_strn(PWD_cpy, 4);

	free(PWD_cpy);
	return (1);
}
/**
 * cd_to_OLDPWD - function that change directory to the OLDPWD
 * and update it to the current PWD
 *
 * @PWD: pointer to a  (PWD)
 *
 *Return: (1) on succsess ,  (-1) if malloc failed or  the path doesn't exist
 */
int cd_to_OLDPWD(char *PWD)
{
	char *OLDPWD = (_getEnv("OLDPWD"));
	char **arr;
	char *oldPWD_cpy;

	if (OLDPWD == NULL)
		return (handling_NULL_OLDPWD(PWD));

	oldPWD_cpy = strdup(OLDPWD);
	arr = tokenize_string(oldPWD_cpy, "=");

	printf("%s\n", arr[1]);

	update_OLDPWD(PWD);
	change_dir(arr[1]);

	free_double_arr(&arr);
	free(oldPWD_cpy);
	return (1);
}
/**
 * cd_Home_path - function that change directory to home path
 *
 *
 * @PWD: pointer to a  (PWD)
 *
 *Return: (1) on succsess ,  (-1) if malloc failed or  the path doesn't exist
 */
int cd_Home_path(char *PWD)
{
	char *home_dir = _getnEnv("HOME", 4);
	char *home_dir_cpy = NULL;
	char **home_dir_arr = NULL;

	if (home_dir == NULL)
		return (1);

	home_dir_cpy = strdup(home_dir);
	is_malloc_failed(home_dir_cpy);

	home_dir_arr = tokenize_string(home_dir_cpy, "=");

	is_malloc_failed(home_dir_arr);

	update_OLDPWD(PWD);
	change_dir(home_dir_arr[1]);

	free(home_dir_cpy);
	free_double_arr(&home_dir_arr);
	return (1);
}
