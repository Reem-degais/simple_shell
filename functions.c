#include "shell.h"

char **_strtok(char *str, ssize_t num_ch)
{
        char **argv,*token, *string_copy = NULL;
        const char *delim = " \n";
        int i,  num_tok = 0;

        string_copy = malloc(sizeof(char) * num_ch);
        if (string_copy== NULL)
        {
                perror("tsh: memory allocation error");
               exit (0);
        }

        _strcpy(string_copy, str);

        token = strtok(str, delim);
        while (token != NULL)
        {
                num_tok++;
                token = strtok(NULL, delim);
        }
        num_tok++;
	argv = malloc(sizeof(char *) * num_tok);
        token = strtok(string_copy, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * _strlen(token));
            _strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

 return (argv);


}



/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
        size_t i;

        for (i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];
        dest[i] = '\0';
        return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *s)
{
        int length = 0;
if (!s)
                return (length);
        for (length = 0; s[length]; length++)
                ;
        return (length);
}
