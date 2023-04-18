#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int ac, char **av, char **env);
void _fork(char **av, char **str, char *envi[]);

#endif
