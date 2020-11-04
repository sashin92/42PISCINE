/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:17:13 by sashin            #+#    #+#             */
/*   Updated: 2020/11/04 23:37:06 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>



char	ft_str_count(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;
	int		*repository;
	int		idx;
	int		length;
	
	i = 0;
	count = 0;
	length = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				repository[idx] = count;
				length = -1;
				++count;
			}
			++j;
		}
		++length;
		++i;
	}
}


int		ft_count_arr_amount(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				++count;


}

char	**ft_split(char *str, char *charset)
{
	char	**str_arr;
	int		count;

	count = 0;
	str_arr = (char *)malloc(sizeof(char *) * count);
}
