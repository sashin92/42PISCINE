/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:13:22 by sashin            #+#    #+#             */
/*   Updated: 2020/11/04 18:55:16 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else
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
