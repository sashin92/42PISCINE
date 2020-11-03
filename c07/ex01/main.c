#include <stdio.h>

int		*ft_range(int min, int max);

int		main(void)
{
	int		*ra;

	ra = ft_range(3, 5);

	printf("%d %d %d %d \n", ra[0], ra[1], ra[2], ra[3]);
}
