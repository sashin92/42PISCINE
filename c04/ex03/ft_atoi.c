/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:44:35 by sashin            #+#    #+#             */
/*   Updated: 2020/10/29 17:44:45 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (2);
	else if (c == ' ')
		return (2);
	else if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else if (c >= '0' && c <= '9')
		return (0);
	else
		return (10);
}

int		ft_fvalue(char *str, int point, int *sign)
{
	int		i;
	int		check;
	int		val;

	i = 0;
	val = 0;
	check = 0;
	while (check < 2)
	{
		if (ft_check(*(str + point)) == -1 && check == 0)
			*sign = (*sign) * (-1);
		else if (ft_check(*(str + point)) == 1 && check == 0)
		{
		}
		else if (ft_check(*(str + point)) == 0)
		{
			check = 1;
			val = (val * 10) + (*(str + point) - '0');
			++i;
		}
		else
			check = 2;
		++point;
	}
	return (val);
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		val;

	i = 0;
	sign = 1;
	while (*(str + i))
	{
		if (ft_check(*(str + i)) == 10)
			return (0);
		else if (ft_check(*(str + i)) >= -1 && ft_check(*(str + i)) <= 1)
		{
			val = ft_fvalue(str, i, &sign);
			break ;
		}
		++i;
	}
	return (sign > 0 ? val : -val);
}
