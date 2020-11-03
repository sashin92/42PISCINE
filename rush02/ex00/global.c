/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:20:56 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 22:43:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_mod_g_tens(char c1, char c2)
{
	g_tens[0] = '\0';
	g_tens[1] = '\0';
	g_tens[2] = '\0';
	g_tens[0] = c1;
	g_tens[1] = c2;
}

char	*ft_str_n_digit(int n)
{
	char	*number;
	int		idx;

	if (!(number = (char *)malloc(sizeof(char) * (n + 1))))	// 필요한 숫자길이의 + 1을 동적할당해줌.
		return (0);
	idx = 0;
	number[idx++] = '1';
	while (idx < n)
		number[idx++] = '0';
	number[idx] = '\0';								// 5자릿수에서 여기까지 왔다면, number에는 "1000"이 저장됐을 것이고, 그다음 위치에 NULL값을 넣어주어 문자열을 완성시킨다. 이 값의 주소를 리턴.
	return (number);
}

void	ft_push_n_digit(int n_of_digit, int minus)			//	thousand, million 따위의 것을 노드에 저장하기 위해 사용하는 함수
{
	char	*to_find;

	to_find = ft_str_n_digit(n_of_digit - minus);			// 가령 12345의 자릿수는 5이고, 여기에 minus 인자값은 1이 들어올 것이기에, 결론적으로 보면 ft_str_n_digit 함수엔 숫자 4가 들어간다. 그러면 number라는 리턴값 주소를 받는데, 이를 to_find에 입력.
	ft_push_number(to_find);								// 그 값의 문자열을 찾은 후 노드로 저장.
	free(to_find);											// 동적할당한 number 변수의 동적할당 해제
}
