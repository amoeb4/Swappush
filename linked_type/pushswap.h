/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:25:13 by dafranco          #+#    #+#             */
/*   Updated: 2022/11/15 00:22:45 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"

typedef struct s_node
{
	int	data;
	struct node *prev;
	struct node *next;
}	t_node;
typedef struct s_stack
{
	t_node			node;
	t_stack		**pile_a;
	t_stack		**pile_b;
}				t_stack;

int				is_strdigit(char *str);
int				ft_issorted(int argc, char **argv);
int				ft_checkdouble(int argc, char **argv);
int				ft_isdigit(char c);
int				ft_atoi(const char *str);
int				ft_valid(int argc, char **argv);
int				ft_isint(char *str);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_sort(int argc, char **argv);
void			ft_self_sort(int argc, char **argv);
void	ft_lstadd_back(t_stack 
long long int		ft_atoll(char *str);

#endif
