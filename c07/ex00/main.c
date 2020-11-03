#include <stdio.h>

char	*ft_strdup(char *src);

int		main(void)
{
	char *has;

	has = ft_strdup("aaaabds");

	printf("%s\n", has);
	return (0);
}
