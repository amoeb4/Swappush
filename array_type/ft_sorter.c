/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 04:37:46 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/10 17:21:34 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

size_t	ft_step_one(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	while (size_b < (argc / 2) + (argc % 2) - 1)
	{
		size_b = argc - size - 1;
		size = intel_one(argc, size, &(*pile_a), &(*pile_b));
		size_b = argc - size - 1;
	}
	return (size);
}

size_t	ft_step_two(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		i;
	int		last;

	i = 1;
	last = size_b;
	while (size_b > 0)
	{
		size_b = argc - size - 1;
		if ((*pile_b)[0] == last)
		{
			size = intel_two_a(argc, size, &(*pile_a), &(*pile_b));
			size_b = argc - size - 1;
			last--;
		}		
		if ((*pile_b)[0] == i)
		{
			size = intel_two_b(argc, size, &(*pile_a), &(*pile_b));
			size_b = argc - size - 1;
			i++;
		}
		if (size_b > 2)
			size = intel_first(argc, size, &(*pile_b), last);
	}
	return (size);
}

size_t	ft_step_thre(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		i;

	size_b = argc - size - 1;
	i = (*pile_a)[size - 1];
	while ((*pile_a)[0] != 1)
	{
		size_b = argc - size - 1;
		if ((*pile_a)[0] == i + 1)
		{
			ft_rotate(size, &(*pile_a));
			ft_putstr("ra\n");
			i++;
		}
		else
			size = intel_tri(argc, size, &(*pile_a), &(*pile_b));
	}
	return (size);
}

size_t	last_tri(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		last;
	int		i;

	i = (*pile_a)[size - 1] + 1;
	size_b = argc - size - 1;
	last = argc - 1;
	while (size_b > 0)
	{
		if ((*pile_b)[0] == last)
		{
			size = intel_tri_b(argc, size, &(*pile_a), &(*pile_b));
			last--;
		}		
		else if ((*pile_b)[0] == i)
		{
			size = intel_tri_c(argc, size, &(*pile_a), &(*pile_b));
			i++;
		}
		else if (size_b > 1)
			size = intel_finder(argc, size, &(*pile_b), last);
		size_b = argc - size - 1;
	}
	return (size);
}

size_t	intel_finder(int argc, size_t size, int **pile_b, int needle)
{
	size_t	size_b;
	int		needlow;

	needlow = is_lowest(argc, size, &(*pile_b));
	size_b = argc - size - 1;
	if (check_pos_b(size_b, &(*pile_b), needle, needlow) == 1)
	{
		ft_rotate(size_b, &(*pile_b));
		ft_putstr("rb\n");
		return (size);
	}
	if (check_pos_b(size_b, &(*pile_b), needle, needlow) == 2)
	{
		size_b = argc - size - 1;
		ft_reverse_rotate(size_b - 1, &(*pile_b));
		ft_putstr("rrb\n");
		return (size);
	}
	return (size);
}
