#include <stdio.h>

char		*ft_strstr(char *str, char *to_find);

int		main(void)
{

	char str[] = "Helloworld!";

	printf("you found that : %s", ft_strstr(str, "l"));
}
