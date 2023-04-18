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
	int  i;
        char *string = NULL;
        size_t n =0;
	ssize_t num_ch;
	char *argv[15];

        if (ac >= 1)
	while(1)
        {
                printf("cisfun$ ");
                
		num_ch = getline(&string, &n, stdin);
		if(num_ch == -1)
		{
                        free(string);
			exit(0);
		}
                i = 0;
                while(string[i])
                {
                        if (string[i] == '\n')
				string[i] = 0;
			i++;
                }
		argv[0]=string;

		_fork(av,argv ,env);
		/**l = 0;
		argv[0]= strtok(buf, " ");
		while (argv[l] != NULL)
		{
			l++;
			argv[l] = strtok(NULL, " ");
		
		}*/
	}
	return(0);
}

/**
 * _fork - creates a new child process.
 * @str: array of string from line command.
 * @envi: environment variable from the parent.
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



