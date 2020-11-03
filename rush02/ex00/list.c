/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:29:27 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 22:48:51 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	push(t_node *node)
{
	if (g_lst->head == NULL)
	{
		g_lst->head = node;
		g_lst->last = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		g_lst->last->next = node;
		node->prev = g_lst->last;
		node->next = NULL;
		g_lst->last = node;
	}
}

t_node	*create_node(char *str)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->str = str;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_print_list(void)
{
	t_node	*ptr;

	ptr = g_lst->head;
	while (ptr)
	{
		ft_putstr(ptr->str);
		if (ptr->next)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		ptr = ptr->next;
	}
}

void	init(void)
{
	if (!(g_lst = (t_list *)malloc(sizeof(t_list))))
		return ;
	g_lst->head = NULL;
	g_lst->last = NULL;
	g_flag = 0;											//	우리가 쓸 글로벌 변수를 동적할당한 후 초기화하고, 추가로 에러핸들링할 플래그도 0으로 맞춰두는 작업, g_lst는 노드를 관리할 때 쓸 것임
}

void	free_list(void)									// 우리가 동적할당한 노드들을 역순으로 모두 할당 해제하는 작업.
{
	t_node	*ptr;
	t_node	*t;

	ptr = g_lst->last;
	while (ptr)
	{
		t = ptr;
		ptr = ptr->prev;
		if (t->str)
			free(t->str);
		t->str = NULL;
		if (t)
			free(t);
		t = NULL;
	}
}
