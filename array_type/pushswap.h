/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:25:13 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/03 06:11:13 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"


#			include <stdio.h>

void			ft_reverse_rotate(size_t size, int **pile);
int				ft_issorted(int argc, char **pile_a);
int				ft_checkdouble(int argc, char **argv);
int				ft_isdigit(char c);
int				ft_atoi(const char *str);
size_t			ft_push_a(int argc, size_t size, int **src, int **dest);
size_t			ft_push_b(int argc, size_t size, int **src, int **dest);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_sort(size_t size, int **pile_a);
void			ft_self_sort(size_t size, int **pile_a);
int				ft_pile_sorted(size_t size, int **pile_a);
void			ft_rotate(size_t size, int **pile);
void			ft_swap(int *pile);
int				ft_valid(int argc, char **argv);
int				ft_isint(char *str);
int				is_strdigit(char *str);
long long int	ft_atoll(char *str);
void			ft_separate(int argc, size_t size, int **pile_a, int **pile_b);
void			ft_indexing(size_t size, int **pile_a);
int				*ft_init_a(size_t size, char **argv, int **pile_a);
int				*ft_init_b(size_t size, char **argv, int **pile_b);
size_t			ft_step_one(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_step_two(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_step_thre(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_repeat(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_one(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_two_b(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_two_a(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_tri_b(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_tri_a(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_tri_c(int argc, size_t size, int **pile_a, int **pile_b);
int				intel_tri(int argc, size_t size, int **pile_a, int **pile_b);
size_t			last_tri(int argc, size_t size, int **pile_a, int **pile_b);

#endif
