/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:53:42 by sashin            #+#    #+#             */
/*   Updated: 2020/11/03 01:16:18 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	long long		i;

	if (nb <= 1)
		return (2);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (ft_find_next_prime(nb + 1));
		++i;
	}
	return (nb);
}
