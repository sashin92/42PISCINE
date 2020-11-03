/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:42:37 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 22:29:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*g_buffer;
char	*g_number;
char	g_tens[3];
t_list	*g_lst;
int		g_flag;

void	ft_num_to_str(void)
{
	int		num_idx;
	int		n_of_digit;

	n_of_digit = ft_strlen(g_number);												// 인자값의 길이(자릿수)
	num_idx = 0;
	if (n_of_digit == 1 && g_number[0] == '0')										// 만약 인자값이 '0'일때
	{
		ft_mod_g_tens(g_number[0], '\0');
		ft_push_number(g_tens);
		return ;
	}
	while (n_of_digit > 0 && !g_flag)												// 자릿수가 한자리 이상일 때(인자값이 '1' 이상일 때)
	{
		if (g_number[num_idx] == '0' && ft_index_modi(&num_idx, &n_of_digit, 1))	// 만약 인자가 1002351 이라면, 1을 확인 후 두번째 자리로 이동할 텐데, 해당 숫자가 0이면 아무런 처리할 필요가 없으니 오른쪽으로 한 칸 옮기는 작업.
			continue;
		else if (n_of_digit % 3 == 0)
			ft_zero(&num_idx, &n_of_digit);											// 만약 인자가 123,456,789 라면, 해당 위치의 함수를 쓸 것이고, 끝난 후에는 인덱스가 4를 가리키고 있을 것임
		else if (n_of_digit % 3 == 2)
			ft_two(&num_idx, &n_of_digit);											// 만약 인자가 23,456,789 이라면, 해당 위치의 함수를 쓸 것이고, 끝난 후에는 인덱스가 4를 가리키고 있을 것임
		else
			ft_one(&num_idx, &n_of_digit);											// 만약 인자가 3,456,789 라면, 해당 위치의 함수를 쓸 것이고, 끝난 후에는 인덱스가 4를 가리키고 있을 것임
	}
}

void	free_memory(void)
{
	if (g_lst)
	{
		free_list();
		free(g_lst);
	}
	if (g_buffer)
		free(g_buffer);
}

void	run(void)
{
	if (!g_buffer)									// 전역 변수 버퍼에 값이 들어가지 못했을때, 에러를 출력한다.
		ft_print_error("Error\n");
	else if (!g_flag && !ft_is_valid_buffer())		// 버퍼에 할당된 값들이 규격에 맞는지 (딕셔너리가 정해진 양식에 맞춰져 있었는지) 확인.
		ft_print_error("Dict Error\n");
	else if (!g_flag && !ft_is_valid_param())		// 들어온 인자값이 규격에 맞는지 (숫자로만 이루어져있는지) 확인.
		ft_print_error("Error\n");
	else if (!g_flag)
	{
		ft_num_to_str();							// 다 문제없으면 해당 숫자를 문자열로 바꿀 것이다.
		if (g_flag)
			ft_print_error("Dict Error\n");
		else
			ft_print_list();
	}
}

int		main(int argc, char *argv[])
{
	init();											// 우리가 쓸 자료형 변수를 동적할당한 후 초기화하고, 추가로 에러핸들링할 플래그도 0으로 맞춰두는 작업
	if (argc == 2)									// 딕셔너리 파일 내용을 버퍼에 쓰고, 숫자 인자값을 캐릭터형으로 전역변수에 저장.
	{
		g_buffer = ft_read_dict();
		g_number = argv[1];
	}
	else if (argc == 3)
	{
		g_buffer = ft_read_argv(argv[1]);
		g_number = argv[2];
	}
	run();											// run!! 윗쪽에 있음
	free_memory();
	return (0);
}
