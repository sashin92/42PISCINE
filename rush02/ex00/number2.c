/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:29:06 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 22:47:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_mod_result_zero(char *number)
{
	ft_mod_g_tens(number[0], '\0');							// 숫자를 세개 씩 끊었을 때 제일 첫번째의 숫자 푸시
	ft_push_number(g_tens);
	ft_push_number("100");									// 그 다음엔 hundred가 와야 되므로 100을 푸시
	if (number[1] == '0' && number[2] >= '1')				// 두번째 자리가 0일때에는 두번째 자리를 읽지 않고 세번째 자리만 노드에 저장한다.
	{
		ft_mod_g_tens(number[2], '\0');
		ft_push_number(g_tens);
	}
	else if (number[1] == '1')								// 두번째 자리가 1일때에는 10~19까지의 값을 써야하기 때문에 왼쪽 처럼 동작한다.
	{
		ft_mod_g_tens(number[1], number[2]);
		ft_push_number(g_tens);
	}
	else if (number[1] >= '2')								// 두번째 자리가 2일때에는 20~90을 찾아야 하므로 셋째자리에 '0'을 넣어서 찾은 후 그 값을 노드에 저장한다.
	{
		ft_mod_g_tens(number[1], '0');
		ft_push_number(g_tens);
		ft_mod_g_tens(number[2], '\0');
		number[2] >= '1' ? ft_push_number(g_tens) : 0;		// 만약 세번째 자리가 1 이상이면 찾아서 노드에 저장하고, 0이면 zero가 나오면 안되기 때문에 그냥 넘어간다.
	}
}

void	ft_mod_result_two(char *number)						// t_mod_result_zero 참고
{
	if (number[0] == '1')
	{
		ft_mod_g_tens(number[0], number[1]);
		ft_push_number(g_tens);
	}
	else
	{
		ft_mod_g_tens(number[0], '0');
		ft_push_number(g_tens);
		if (number[1] != '0')
		{
			ft_mod_g_tens(number[1], '\0');
			ft_push_number(g_tens);
		}
	}
}

void	ft_mod_result_one(char *number)						// t_mod_result_zero 참고
{
	ft_mod_g_tens(number[0], '\0');
	ft_push_number(g_tens);
}
