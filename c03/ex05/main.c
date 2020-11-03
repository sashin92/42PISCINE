#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{
	char	s1[70] = "abc";
	char	s2[70] = "12345";
	char	s3[70] = "abc";
	char	s4[70] = "12345";

		printf("your val : %u\n", ft_strlcat(s1, s2, 11));
		printf("destination? : %s\n", s1);
   		  printf("your val : %lu\n", strlcat(s3, s4, 11));
		printf("destination? : %s\n", s3);





}


