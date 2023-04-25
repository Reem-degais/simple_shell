#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int main(int ac, char **av, char **env);
void _fork(char **av, char **str, char *envi[]);
int _strcmp(char a[],char b[]);
char *_strcat(char *dest, const char *src);
char *checkf(char *str );
int shellby_env(char **args, char __attribute__((__unused__)) **front);
char **_strtok(char *str, ssize_t num_ch);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);

#endif
