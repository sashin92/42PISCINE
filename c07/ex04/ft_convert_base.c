/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:47:34 by sashin            #+#    #+#             */
/*   Updated: 2020/11/03 21:13:38 by sashin           ###   ########.fr       */
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
	while (ft_base_index(nbr[i], base_from) != -1)
	{
		val = (val * length) + i;
		++i;
	}
	return (val)
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

	i = 0;
	if (nbr < length)
	{
		*digit = *digit + 1;
		return ;
	}
	if (nbr > length)
	{
		*digit = *digit + 1;
		ft_nbr_tobase_digit((nbr / length), length, digit);
	}
	return ;
}

void	*ft_nbr_tobase_digit(int nbr, int length, int *digit)
{
	int		i;

	i = 0;
	if (nbr < length)
	{
		*digit = *digit + 1;
		return ;
	}
	if (nbr > length)
	{
		*digit = *digit + 1;
		ft_nbr_tobase_digit((nbr / length), length, digit);
	}
	return ;
}

void	ft_nbr_to_str(int nbr, char *base, char *result, int length)
{
	char num;

	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			result = base[-(nbr % length)];
			ft_nbr_to_str(-(nbr / length), base, result + 1, length);
			write(1, &num, sizeof(char));

			return ;
		}
		nbr = nbr * (-1);
	}
	num = base[nbr % length];
	if (nbr >= length)
	{
		nbr = nbr / length;
		ft_putnbr(nbr, base, length);
	}
	write(1, &num, sizeof(char));
}


char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bflength;
	int		btlength;
	int		ten_val;
	int		digit;
	char	*result;

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
	result = (char *)malloc(sizeof(char) * (digit + 1));
	ft_nbr_base(ten_val, btlength, result);
}
