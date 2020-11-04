#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{
	char dest[50] = "a";
	char src[50] = "1234";
	char dest2[50] = "a";
	char src2[50] = "1234";
	int		val;
	int		val2;

	val = ft_strlcat(dest, src, 7);
	printf("val is : %d\ndest is :%s\n", val, dest);
	val2 = strlcat(dest2, src2, 7);
	printf("val is : %d\ndest is :%s\n", val2, dest2);
	return (0);

}