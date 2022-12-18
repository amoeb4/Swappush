/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:43:40 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/13 06:37:04 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "pushswap.h"
#include "stdio.h"

size_t	part_three(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	if ((*pile_b)[0] == 4)
	{
		size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
		ft_putstr("pa\n");
		size_b = argc - size - 1;
		return (size = part_four(argc, size, &(*pile_a), &(*pile_b)));
	}
	size_b = argc - size - 1;
	if ((*pile_a)[0] > (*pile_a)[1] && (*pile_b)[0] < (*pile_b)[1])
	{
		ft_swap(*pile_a);
		ft_swap(*pile_b);
		ft_putstr("sa\n");
	}
	if ((*pile_b)[0] < (*pile_b)[1])
	{
		ft_swap(*pile_b);
		ft_putstr("sb\n");
	}
	size_b = argc - size - 1;
	return (size = part_four(argc, size, &(*pile_a), &(*pile_b)));
}

size_t	part_four(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	while (size_b > 0)
	{
		if ((*pile_b)[0] < (*pile_b)[1] && size_b > 1)
		{
			ft_swap(*pile_b);
			ft_putstr("sb\n");
		}
		if ((*pile_a)[0] > (*pile_a)[1])
		{
			ft_swap(*pile_a);
			ft_putstr("sa\n");
		}
		if (size_b)
		{
			size_b = argc - size - 1;
			size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
			ft_putstr("pa\n");
			size_b = argc - size - 1;
		}
	}
	return (size = last_check(argc, size, &(*pile_a)));
}

size_t	last_check(int argc, size_t size, int **pile_a)
{
	if ((*pile_a)[0] == 2)
	{
		ft_swap((*pile_a));
		ft_putstr("sa\n");
	}
	return (size);
}
