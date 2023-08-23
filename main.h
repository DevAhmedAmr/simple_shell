#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
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
extern char **environ;
int interactive_mode(char **cmd, char ***args);
char *_getEnv(char *path);
void free_double_arr(char ***args);
char **tokenize_string(char *path, char *del);
void free_3d_arr(char ***args);
void print3d_arr(char ***threeD_arr);
void print_2d_arr(char **args);
int non_interactive(char **cmd, char ***args, char *app_name);
void non_(char **cmd, char ***args);
int ExecuteCommand(char *input, char **args);
int builtIns(char *cmd, char **args, int status);
void print_2d_arr(char **args);
int append_to_path(char **path, char *input);

char *is_executable_in_env_paths(char *input,
								 int command_count,
								 char *app_name);

int tryExecuteCommand(char *input, char **args,
					  int command_count,
					  char *app_name);

#endif
