#include <stdio.h>

int		ft_is_prime(int nb);

int		main(void)
{
	printf("소수? : %d\n", ft_is_prime(11));
	printf("소수? : %d\n", ft_is_prime(9));
	printf("소수? : %d\n", ft_is_prime(2147483647));
}
