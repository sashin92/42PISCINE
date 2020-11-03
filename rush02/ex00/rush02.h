/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghkim <sanghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:59:02 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 15:17:56 by sanghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_node
{
	char			*str;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_list
{
	t_node			*head;
	t_node			*last;
}				t_list;

extern char		*g_buffer;
extern char		*g_number;
extern char		g_tens[3];
extern t_list	*g_lst;
extern int		g_flag;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strndup(char *str, int n);
void			push(t_node *node);
t_node			*create_node(char *str);
void			ft_print_list(void);
void			init(void);
void			free_list(void);
void			ft_print_error(char *str);
char			*ft_read_dict(void);
char			*ft_read_argv(char *file);
char			*ft_str_n_digit(int n);
void			ft_push_number(char *to_find);
int				ft_is_valid_param(void);
int				ft_is_valid_buffer(void);
int				ft_index_modi(int *num_idx, int *n_of_digit, int plus);
void			ft_mod_g_tens(char c1, char c2);
void			ft_mod_result_zero(char *number);
void			ft_mod_result_two(char *number);
void			ft_mod_result_one(char *number);
void			ft_push_n_digit(int n_of_digit, int minus);
void			ft_zero(int *num_idx, int *n_of_digit);
void			ft_one(int *num_idx, int *n_of_digit);
void			ft_two(int *num_idx, int *n_of_digit);
void			ft_num_to_str(void);
void			free_memory(void);
int				ft_is_space(char c);

#endif
