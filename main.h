#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
extern int counter;
extern char *app_name;
#define FREE_2D_ARGS_AND_CMD    \
	{                           \
		free_double_arr(&args); \
		free(cmd);              \
	}
#define FREE_ARGS_AND_CMD \
	{                     \
		free(*args);      \
		free(cmd);        \
	}

#define is_malloc_failed(allocation)                     \
	{                                                    \
		if (allocation == NULL)                          \
		{                                                \
			fprintf(stderr, "memory allocation failed"); \
			return -1;                                   \
		}                                                \
	}

extern char **environ;
int interactive_mode(char **cmd, char ***args);
char *_getEnv(char *path);
void free_double_arr(char ***args);
char **tokenize_string(char *path, char *del);
void free_3d_arr(char ***args);
void print3d_arr(char ***threeD_arr);
void print_2d_arr(char **args);
int non_interactive(char **cmd, char ***args);
void non_(char **cmd, char ***args);
int ExecuteCommand(char *input, char **args);
int builtIns(char *cmd, char **args, int *status);
void print_2d_arr(char **args);
int append_to_path(char **path, char *input);
int double_arr_len(char **arr);
char *is_executable_in_env_paths(char *input);
int tryExecuteCommand(char *input, char **args);
int set_env(char **input);
int unset_env(char **input);
int change_dir(char *path);
char *_getnEnv(char *env, int n);
int Exit_fun(char *cmd, char **args, int *status);
int positive_parseInt(char *str);
void print_strn(char *str, int n);
int handling_NULL_OLDPWD(char *PWD);
int cd_to_OLDPWD(char *PWD);
int cd_Home_path(char *PWD);
int cd(char **args);
int update_OLDPWD(char *old_pwd_path);
#endif
