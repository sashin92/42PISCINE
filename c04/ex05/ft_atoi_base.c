/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:56:18 by sashin            #+#    #+#             */
/*   Updated: 2020/10/29 19:52:34 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cbase(char *b, int blength)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(b + i))
	{
		if (b[i] == '\t' || b[i] == '\n' || b[i] == '\v' || b[i] == '+')
			return (1);
		else if (b[i] == '\f' || b[i] == '\r' || b[i] == ' ' || b[i] == '-')
			return (1);
		++i;
	}
	i = -1;
	while (++i < blength - 1)
	{
		j = i + 1;
		while (j < blength)
		{
			if (*(b + i) == *(b + j))
				return (1);
			++j;
		}
	}
	return (0);
}

int		ft_cstr(char c, char *base)
{
	int		i;

	i = 0;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (2);
	else if (c == ' ')
		return (2);
	else if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	while (*(base + i))
	{
		if (c == *(base + i))
			return (0);
		++i;
	}
	return (10);
}

int		ft_baseindex(char *str, char *base, int point)
{
	int		i;

	i = 0;
	while (*(base + i))
	{
		if (*(str + point) == *(base + i))
			return (i);
		++i;
	}
	return (0);
}

int		ft_fvalue(char *str, char *base, int point, int blength)
{
	int		check;
	int		val;
	int		sign;

	val = 0;
	check = 0;
	sign = 1;
	while (check < 2)
	{
		if (ft_cstr(*(str + point), base) == -1 && check == 0)
			sign = sign * (-1);
		else if (ft_cstr(*(str + point), base) == 1 && check == 0)
		{
		}
		else if (ft_cstr(*(str + point), base) == 0)
		{
			check = 1;
			val = (val * blength) + ft_baseindex(str, base, point);
		}
		else
			check = 2;
		++point;
	}
	val = sign * val;
	return (val);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		blength;
	int		val;

	i = 0;
	blength = 0;
	val = 0;
	while (*(base + blength))
		++blength;
	if (blength <= 1 || ft_cbase(base, blength) == 1)
		return (0);
	while (str[i])
	{
		if (ft_cstr(str[i], base) == 10)
			return (0);
		else if (ft_cstr(str[i], base) >= -1 && ft_cstr(str[i], base) <= 1)
		{
			val = ft_fvalue(str, base, i, blength);
			break ;
		}
		++i;
	}
	return (val);
}
