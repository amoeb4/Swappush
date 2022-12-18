/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:25:13 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/13 06:36:46 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
//				| Appels de fonctions |
size_t			ft_call(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_call_one(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_call_two(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_call_thre(int argc, size_t size, int **pile_a, int **pile_b);
//				| Manipulations des piles |
void			ft_rotate(size_t size, int **pile);
void			ft_reverse_rotate(size_t size, int **pile);
size_t			ft_push_a(int argc, size_t size, int **src, int **dest);
size_t			ft_push_b(int argc, size_t size, int **src, int **dest);
void			ft_swap(int *pile);
//				| Gestion d'erreur |
int				ft_issorted(int argc, char **pile_a);
int				is_strdigit(char *str);
int				ft_valid(int argc, char **argv);
int				ft_checkdouble(int argc, char **argv);
int				ft_isdigit(char c);
int				ft_isint(char *str);
long long int	ft_atoll(char *str);
//				| Parsing |
int				ft_atoi(const char *str);
//				| Initialisation |
int				*ft_init_a(size_t size, char **argv, int **pile_a);
int				*ft_init_b(size_t size, char **argv, int **pile_b);
void			ft_indexing(size_t size, int **pile_a);
void			ft_separate(int argc, size_t size, int **pile_a, int **pile_b);
//				| Instructions |	
void			ft_putchar(char c);
void			ft_putstr(const char *str);
//				| Protocoles simples |
//					< 6 arguments
size_t			ft_self_sort(size_t size, int **pile_a);
int				ft_pile_sorted(size_t size, int **pile_a);
size_t			ft_more(int argc, size_t size, int **pile_a, int **pile_b);
size_t			sort_five(int argc, size_t size, int **pile_a, int **pile_b);
size_t			part_two(int argc, size_t size, int **pile_a, int **pile_b);
size_t			part_three(int argc, size_t size, int **pile_a, int **pile_b);
size_t			part_four(int argc, size_t size, int **pile_a, int **pile_b);
size_t			last_check(int argc, size_t size, int **pile_a);
//					1 Argument desordonne
size_t			ft_one(int argc, size_t size, int **pile_a, int **pile_b);
size_t			xintel_one(int argc, size_t size, int **pile_a, int **pile_b);
int				ft_spikes(int argc, size_t size, int **pile_a);
size_t			ft_resort(int argc, size_t size, int **pile_a);
int				ft_specials(int argc, size_t size, int **pile_a);
//				| Protocoles complexes >100 |
size_t			ft_step_one(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_step_two(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_step_thre(int argc, size_t size, int **pile_a, int **pile_b);
size_t			ft_repeat(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_one(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_two_b(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_two_a(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_tri_b(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_finder(int argc, size_t size, int **pile_a, int needle);
size_t			intel_tri_c(int argc, size_t size, int **pile_a, int **pile_b);
size_t			intel_tri(int argc, size_t size, int **pile_a, int **pile_b);
int				intel_last(int argc, size_t size, int **pile_a, int **pile_b);
size_t			last_tri(int argc, size_t size, int **pile_a, int **pile_b);
int				check_pos_b(size_t size, int **pile_b, int needle, int needlow);
size_t			intel_first(int argc, size_t size, int **pile_a, int needle);
int				is_lowest(int argc, size_t size, int **pile_b);
size_t			ft_call(int argc, size_t size, int **pile_b, int **pile_a);
size_t			intel_tri_d(int argc, size_t size, int **pile_a, int **pile_b);

#endif
