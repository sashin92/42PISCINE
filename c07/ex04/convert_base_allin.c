/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:47:34 by sashin            #+#    #+#             */
/*   Updated: 2020/11/04 18:03:33 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_index(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		++i;
	}
	return (-1);
}

int		ft_is_atoi_base(char *nbr, char *base_from, int length)
{
	int		i;
	int		val;
	int		idx;
	int		sign;

	i = 0;
	val = 0;
	sign = 1;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		++i;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = sign * (-1);
		++i;
	}
	while ((idx = ft_base_index(nbr[i], base_from)) != -1)
	{
		val = (val * length) + idx;
		++i;
	}
	return (sign * val);
}

int		ft_is_base_overlap(char *base, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int		ft_is_base_correct(char *base)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	while (base[i])
	{
		if ((base[i] == ' ' || (base[i] >= 9 && base[i] <= 13) ||
				base[i] == '+' || base[i] == '-'))
			return (0);
		++i;
	}
	length = i;
	if (length <= 1)
		return (0);
	if (!ft_is_base_overlap(base, length))
		return (0);
	return (1);
}

void	ft_nbr_tobase_digit(int nbr, int length, int *digit)
{
	int		i;
	int		abs_nbr;

	if (nbr >= 0)
		abs_nbr = nbr;
	else if (nbr < 0)
		abs_nbr = -nbr;
	i = 0;
	if (abs_nbr < length)
	{
		*digit = *digit + 1;
		return ;
	}
	if (abs_nbr >= length)
	{
		*digit = *digit + 1;
		ft_nbr_tobase_digit((abs_nbr / length), length, digit);
	}
	return ;
}

char	*ft_nbr_is_positive(int nbr, char *base, int digih, int length)
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
		val = ft_nbr_is_negative(nbr, base, digih, length);
	else if (nbr > 0)
		val = ft_nbr_is_positive(nbr, base, digih, length);
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
