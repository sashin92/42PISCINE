#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

int		main(void)
{
	char **strs;
	char *lstr;

	strs = (char **)malloc(sizeof(char*) * 10);

	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "my_name";
	strs[3] = "is";
	strs[4] = "SB!";

	lstr = ft_strjoin(5, strs, ":_:");

	printf("%s\n", lstr);
	return (0);
}
