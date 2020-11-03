/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:58:40 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 22:20:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_read_dict(void)
{
	int		fd;
	char	*buffer;
	int		fr;

	if (!(buffer = (char *)malloc(sizeof(char) * 2049)))		// 캐릭터형 포인터에다가 메모리를 충분히 할당, 만약 할당을 하지 못한다면 NULL을 반환하기 때문에 조건문에 따라 0을 리턴할 것임
		return (0);
	if ((fd = open("numbers.dict", O_RDONLY)) == -1)			// 파일을 읽기전용으로 염. 실패 시, 플래그를 세우고, "Error" 출력 후, 동적할당된 버퍼를 리턴함 (동적할당 해제하기 위해)
	{
		g_flag = 1;
		ft_print_error("Error\n");
		return (buffer);
	}
	if ((fr = read(fd, buffer, 2048)) == -1)					// 파일을 읽어서 그 내용을 버퍼에 써준다. fr값은 파일을 읽은 값 만큼의 바이트를 리턴해준 걸 받아온다.
	{
		g_flag = 1;
		ft_print_error("Error\n");
	}
	else
	{
		buffer[fr] = 0;											// 버퍼가 읽어온 값 다음에 NULL을 넣어줘서 문자열을 완성시킨다.
		close(fd);												// 파일을 닫는다.
	}
	return (buffer);											// 해당 리턴값 주소는 main문에서 보면 g_buffer에 저장될 것임.
}

char	*ft_read_argv(char *file)
{
	int		fd;
	char	*buffer;
	int		fr;
	int		fs;

	if (!(buffer = malloc((sizeof(char) * 2049))))
		return (0);
	fs = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		g_flag = 1;
		ft_print_error("Error\n");
		return (buffer);
	}
	if ((fr = read(fd, buffer, 2048)) < 0)
	{
		g_flag = 1;
		ft_print_error("Error\n");
	}
	else
	{
		buffer[fr] = 0;
		close(fd);
	}
	return (buffer);
}
