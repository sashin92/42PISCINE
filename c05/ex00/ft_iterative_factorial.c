/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:02:11 by sashin            #+#    #+#             */
/*   Updated: 2020/10/29 12:16:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		val;
	int		i;

	i = 1;
	val = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i <= nb)
	{
		val = val * i;
		++i;
	}
	return (val);
}
