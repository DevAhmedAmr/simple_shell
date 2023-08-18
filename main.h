#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
int interactive_mode(char **cmd, char ***args);
char *_getEnv(char *path);
void free_double_arr(char **args);
char **tokenize_string(char *path, char *del);
void free_3d_arr(char ***args);
void print3d_arr(char ***threeD_arr);
void printArgs(char **args);
int non_interactive(char **cmd, char ***args);
void non_(char **cmd, char ***args);
char *check_is_executable_in_paths(char *input);
void printArgs(char **args);
int append_to_path(char **path, char *input);
int tryExecuteCommand(char *input, char **args);
int ExecuteCommand(char *input, char **args);

#endif
