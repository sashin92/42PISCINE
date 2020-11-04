#include <stdio.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main(int argc, char **argv)
{
	char	*val;

	(void)argc;
	val = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("nbr : %s\n", val);
	
	free(val);

	return (0);
}
