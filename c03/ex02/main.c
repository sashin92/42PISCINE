#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int		main(void)
{
	char	dest[100] = "aba";
	char	src[100] = "123";

	printf("your val : %s\n", ft_strcat(dest, src));
}
