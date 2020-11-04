/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:47:34 by sashin            #+#    #+#             */
/*   Updated: 2020/11/04 18:55:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_index(char c, char *base);
int		ft_is_atoi_base(char *nbr, char *base_from, int length);
int		ft_is_base_overlap(char *base, int length);
int		ft_is_base_correct(char *base);
void	ft_nbr_tobase_digit(int nbr, int length, int *digit);

char	*ft_nbr_is_positive(int nbr, char *base, int digit, int length)
{
	int		i;
	char	*val;

	val = (char *)malloc(sizeof(char) * (digit + 1));
	val[digit] = 0;
	i = digit;
	while (i > 0)
	{
		val[i - 1] = base[nbr % length];
		nbr = nbr / length;
		i--;
	}
	return (val);
}

char	*ft_nbr_is_negative(int nbr, char *base, int digit, int length)
{
	int		i;
	char	*val;

	val = (char *)malloc(sizeof(char) * (digit + 2));
	val[digit + 1] = 0;
	i = digit;
	nbr = nbr * (-1);
	val[0] = '-';
	while (i > 0)
	{
		val[i] = base[nbr % length];
		nbr = nbr / length;
		i--;
	}
	return (val);
}

char	*ft_nbr_to_str(int nbr, char *base, int digit, int length)
{
	char	*val;

	if (nbr < 0)
		val = ft_nbr_is_negative(nbr, base, digit, length);
	else
		val = ft_nbr_is_positive(nbr, base, digit, length);
	return (val);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bflength;
	int		btlength;
	int		ten_val;
	int		digit;

	if (!ft_is_base_correct(base_from) || !ft_is_base_correct(base_to))
		return (0);
	bflength = 0;
	btlength = 0;
	digit = 0;
	while (base_from[bflength])
		++bflength;
	while (base_to[btlength])
		++btlength;
	ten_val = ft_is_atoi_base(nbr, base_from, bflength);
	ft_nbr_tobase_digit(ten_val, btlength, &digit);
	return (ft_nbr_to_str(ten_val, base_to, digit, btlength));
}
