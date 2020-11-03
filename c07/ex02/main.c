#include <stdio.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max);

int		main(void)
{
	int		*ha;
	int		rang;
	
	rang = ft_ultimate_range(&ha, -1, 2);


	printf("%d\n", rang);
	printf("%d %d %d\n", ha[0], ha[1], ha[2]);
}
