#include "shell.h"

char *checkf(char *str )
{
	DIR *dir = opendir("/bin/");
	struct dirent *file;
	char *m;
	char *l;

	if (dir == NULL)
		return (NULL);
	file = readdir(dir);
	while (file)
	{
		m = file->d_name;
		if (_strcmp(m,str) == 0)
		{
			l = _strcat("/bin/", str);
			closedir(dir);
			return (l);

		}
		file = readdir(dir);

	}

	closedir(dir);
	return (NULL);

}

char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}
