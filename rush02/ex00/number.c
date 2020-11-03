/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:37:17 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 22:32:52 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_push_number(char *to_find)
{
	char	*ptr;
	char	*start;
	char	*result;

	if (!(ptr = ft_strstr(g_buffer, to_find)))
	{
		g_flag = 1;
		return ;
	}
	while (*ptr && *ptr >= '0' && *ptr <= '9')
		ptr++;
	while (*ptr && ft_is_space(*ptr))
		ptr++;
	if (*ptr == ':')
		ptr++;
	while (*ptr && ft_is_space(*ptr))
		ptr++;
	start = ptr;
	while (*ptr && *ptr != '\n')
		ptr++;
	result = ft_strndup(start, ptr - start);
	push(create_node(result));
}

int		ft_index_modi(int *num_idx, int *n_of_digit, int plus)
{
	*num_idx += plus;
	*n_of_digit -= plus;
	return (1);
}

void	ft_zero(int *num_idx, int *n_of_digit)
{
	ft_mod_result_zero(&g_number[*num_idx]);		// 	가령 123,456이 인자고, 인덱스가 0일 때, '123'을 문자열로 바꿔주는 작업
	if (*n_of_digit != 3)
		ft_push_n_digit(*n_of_digit, 2);			// << 해당 함수는 위의 행위 이후 (thousand, million) 따위의 것을 출력하기 위해 사용
	ft_index_modi(num_idx, n_of_digit, 3);			// 자릿수를 셋 만큼 옮겨준다(위의 숫자의 경우 인덱스는 4를 카리킨다.)
}

void	ft_one(int *num_idx, int *n_of_digit)
{
	ft_mod_result_one(&g_number[*num_idx]);			// 	가령 23,456이 인자고, 인덱스가 0일 때, '23'을 문자열로 바꿔주는 작업
	if (*n_of_digit != 1)
		ft_push_n_digit(*n_of_digit, 0);			// << 해당 함수는 위의 행위 이후 (thousand, million) 따위의 것을 출력하기 위해 사용
	ft_index_modi(num_idx, n_of_digit, 1);			// 자릿수를 셋 만큼 옮겨준다(위의 숫자의 경우 인덱스는 4를 카리킨다.)
}

void	ft_two(int *num_idx, int *n_of_digit)
{
	ft_mod_result_two(&g_number[*num_idx]);			// 	가령 3,456이 인자고, 인덱스가 0일 때, '3'을 문자열로 바꿔주는 작업
	if (*n_of_digit != 2)
		ft_push_n_digit(*n_of_digit, 1);			// << 해당 함수는 위의 행위 이후 (thousand, million) 따위의 것을 출력하기 위해 사용
	ft_index_modi(num_idx, n_of_digit, 2);			// 자릿수를 셋 만큼 옮겨준다(위의 숫자의 경우 인덱스는 4를 카리킨다.)
}
