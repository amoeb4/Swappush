/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autosort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:10:11 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/13 04:42:17 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "pushswap.h"

int	ft_pile_sorted(size_t size, int **pile_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		if (((*pile_a)[i]) > ((*pile_a)[i + 1]))
			j++;
		i++;
	}
	return (j);
}

size_t	ft_self_sort(size_t size, int **pile_a)
{
	if (size == 3)
	{
		if ((*pile_a)[0] == 3)
		{
			ft_rotate(size, *&pile_a);
			ft_putstr("ra\n");
			if (ft_pile_sorted(size, &(*pile_a)) == 0)
				return (size);
		}
		if ((*pile_a)[1] == 3)
		{
			ft_reverse_rotate(size - 1, *&pile_a);
			ft_putstr("rra\n");
			if (ft_pile_sorted(size, &(*pile_a)) == 0)
				return (size);
		}
		ft_swap(*pile_a);
		ft_putstr("sa\n");
	}
	return (size);
}

size_t	ft_more(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	while ((*pile_a)[0] != argc - 1)
	{
		ft_rotate(size, &(*pile_a));
		ft_putstr("ra\n");
	}
	size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
	ft_putstr("pb\n");
	size_b = argc - size - 1;
	ft_self_sort(size, &(*pile_a));
	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	ft_putstr("pa\n");
	size_b = argc - size - 1;
	ft_rotate(size, &(*pile_a));
	ft_putstr("ra\n");
	return (size);
}

size_t	sort_five(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	while ((*pile_a)[size - 1] != 5)
	{
		if ((*pile_a)[0] == 5)
		{
			ft_rotate(size, &(*pile_a));
			ft_putstr("ra\n");
			return (size = part_two(argc, size, &(*pile_a), &(*pile_b)));
		}
		if ((*pile_a)[size - 2] == 5)
		{
			ft_reverse_rotate(size - 1, &(*pile_a));
			ft_putstr("rra\n");
		}
		else
		{
			size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
			ft_putstr("pb\n");
		}
	}
	return (size = part_two(argc, size, &(*pile_a), &(*pile_b)));
}

size_t	part_two(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	while (size > 2)
	{
		size_b = argc - size - 1;
		size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
		ft_putstr("pb\n");
	}
	while ((*pile_a)[0] != 4 && (*pile_b)[0] != 4)
	{
		size_b = argc - size - 1;
		if ((*pile_b)[1] == 4)
		{
			ft_swap(*pile_b);
			ft_putstr("sb\n");
		}
		if ((*pile_b)[2] == 4)
		{
			ft_reverse_rotate(size_b - 1, &(*pile_b));
			ft_putstr("rrb\n");
		}
	}
	return (size = part_three(argc, size, &(*pile_a), &(*pile_b)));
}
