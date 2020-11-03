#include <stdio.h>

int		ft_find_next_prime(int nb);

int		main(void)
{
	printf("소수? : %d\n", ft_find_next_prime(2147483630));
	printf("소수? : %d\n", ft_find_next_prime(7));
	printf("소수? : %d\n", ft_find_next_prime(8));
	printf("소수? : %d\n", ft_find_next_prime(9));
}
