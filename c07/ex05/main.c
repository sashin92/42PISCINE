#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);


int		main(int argc, char **argv)
{
	char	**result;
	int		i;

	if (argc == 1)
		return (0);
	result = ft_split(argv[1], argv[2]);

	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		++i;
	}
	return (0);
}
