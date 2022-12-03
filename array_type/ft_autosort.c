/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autosort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:10:11 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/03 05:36:47 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_sort(size_t size, int **pile_a)
{
	if (size == 2)
	{
		ft_swap(*pile_a);
		ft_putstr("sa\n\n[OK]\n");
	}
}

int	ft_pile_sorted(size_t size, int **pile_a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*pile_a)[i]) > ((*pile_a)[i + 1]))
			return (0);
		i++;
	}
	ft_putstr("\n[OK]\n");
	return (1);
}

void	ft_self_sort(size_t size, int **pile_a)
{
	if (size == 3)
	{
		if ((*pile_a)[0] == 3)
		{
			ft_rotate(size, *&pile_a);
			ft_putstr("ra\n");
			if (ft_pile_sorted(size - 2, *&pile_a) == 1)
				return ;
		}
		if ((*pile_a)[1] == 3)
		{
			ft_reverse_rotate(size, *&pile_a);
			ft_putstr("rra\n");
			if (ft_pile_sorted(size - 2, *&pile_a) == 1)
				return ;
		}
		ft_swap(*pile_a);
		ft_putstr("sa\n\n[OK]\n");
		return ;
	}
}
