#include "shell.h"

/**
 * main - main function of simple shell.
 * @ac: number of arguments.
 * @av: array of arguments.
 * @env: enviroment variable.
 * Return: 0.
 */

int main(int ac, char **av, char **env)
{
	int  i, k;
	char *string = NULL;
	size_t n = 0;
	ssize_t num_ch;
	char **argv;

	if (ac >= 1)
		while (1)
		{
			if (isatty(STDIN_FILENO))
				printf("cisfun$ ");

			num_ch = getline(&string, &n, stdin);
			if (num_ch == -1)
			{
				free(string);
				exit(0);
			}
			i = 0;
			while (string[i])
			{
				if (string[i] == '\n')
					string[i] = 0;
				i++;
			}

			argv = _strtok(string, num_ch);
			
			if (_strcmp("exit", argv[0]) == 0)
				break;
			
			if (_strcmp("env", argv[0]) == 0)
				 for (k = 0; env[k] != NULL; k++)
					 printf("\n%s", env[k]);
			/**re = checkf(argv[0]);
			if (re != NULL)
				argv[0] = re;*/
			_fork(av, argv, env);


	
		}

	return (0);
}

/**
 * _fork - creates a new child process.
 * @str: array of string from line command.
 * @envi: environment variable from the parent.
 * @av : array of argument.
 * Return: nothing.
 */
void _fork(char **av, char **str, char *envi[])
{
	pid_t child_pid;
	int status, v;


	child_pid = fork();

	if (child_pid == -1)
	{
		return;
	}

	if (child_pid == 0)
	{
		v = execve(str[0], str, envi);
		if (v  == -1)
			printf("%s: No such file or directory\n", av[0]);
	}
	else
		wait(&status);

}

/**
 * _strcmp - compare two strings.
 * @a: first string.
 * @b: second string.
 * Return: 0 if thay are same ,1 if they not.
 */
int _strcmp(char a[], char b[])
{
	int flag = 0, i = 0; 

	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}



