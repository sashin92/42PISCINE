#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int		main(void)
{
	char	s1[] = "za";
	char	s2[] = "vc";

	printf("value is : %d", ft_strncmp(s1, s2, 2));
}
