#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int		main(void)
{
	char	dest[100] = "you are ";
	char	src[100] = "HAPPY!";

	printf("hey! : %s", ft_strncat(dest, src, 0));
}
