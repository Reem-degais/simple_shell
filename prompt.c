#include "shell.h"

int prompt(char **av)
{
        
	int  i, s, v, l;
        char *buf = NULL;
        size_t n =0;
	ssize_t num_ch;
	char *argv[15];
	pid_t  m;

        while(1)
        {
                printf("cisfun$ ");
                num_ch = getline(&buf, &n, stdin);

                if(num_ch == -1)
		{
                        free(buf);
	
		}
                i = 0;
                while(buf[i])
                {
                        if (buf[i] == '\n')
                                buf[i] = 0;
			i++;
                }
		l = 0;
		argv[l]= strtok(buf, " ");
		while (argv[l] != NULL)
		{
			l++;
			argv[l] = strtok(NULL, " ");
		}
		m = fork();
		if (m == -1)
		{
			free(buf);

		}
		if (m == 0)
		{
			v = execve(argv[0], argv, NULL);
			if (v  == -1)
				printf("%s: No such file or directory\n", av[0]);


		}
		else 
			wait (&s);
	
	}
	return(0);
}
