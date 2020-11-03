/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:38:37 by sashin            #+#    #+#             */
/*   Updated: 2020/10/29 21:05:29 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		val;

	i = 1;
	val = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i <= power)
	{
		val = val * nb;
		++i;
	}
	return (val);
}
