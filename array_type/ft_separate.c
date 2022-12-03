/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:49:48 by dafranco          #+#    #+#             */
/*   Updated: 2022/11/30 00:32:39 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_separate(int argc, size_t size, int **pile_a, int **pile_b)
{
	int	i;
	int	j;

	j = (size / 2) - (size % 2);
	i = 0;
	while (i < j)
	{
		if ((*pile_a)[0] <= j)
			ft_push_a(argc, size, *&pile_a, *&pile_b);
		if ((*pile_a)[0] > j)
			ft_rotate(size, *&pile_a);
		i++;
	}
}
