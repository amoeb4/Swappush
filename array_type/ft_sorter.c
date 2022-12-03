/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 04:37:46 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/03 06:19:46 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "pushswap.h"
#include "stdio.h"

size_t	ft_step_one(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		pivot;

	pivot = (size / 2);
	size_b = argc - size - 1;
	while (size_b < pivot)
	{
		if ((*pile_a)[0] == 1)
		{
			size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
			size_b = argc - size - 1;
			ft_putstr("pa\n");
			if (size_b > 1 && size_b != pivot)
			{
				ft_rotate(size_b, &(*pile_b));
				ft_putstr("rb\n");
			}
		}
		size_b = argc - size - 1;
		size = intel_one(argc, size, &(*pile_a), &(*pile_b));
		size_b = argc - size - 1;
	}
	ft_reverse_rotate(size_b - 1, &(*pile_b));
	ft_putstr("rrb\n");
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
		if ((*pile_b)[0] == last)
		{
			size = intel_two_b(argc, size, &(*pile_a), &(*pile_b));
			last--;
		}		
		else if ((*pile_b)[0] == i)
		{
			size = intel_two_b(argc, size, &(*pile_a), &(*pile_b));
			i++;
		}
		else if ((*pile_b[0]) != last || (*pile_b[0] != i))
		{
			size = intel_two_a(argc, size, &(*pile_a), &(*pile_b));
		}
		size_b = argc - size - 1;
	}
	return (size);
}

size_t	ft_step_thre(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		i;
	int		j;

	size_b = argc - size - 1;
	i = intel_tri(argc, size, &(*pile_a), &(*pile_b));
	j = argc / 2;
	printf("%d", i);
	while (j > 0)
	{
		size_b = argc - size - 1;
		size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
		size_b = argc - size - 1;
		ft_putstr("pa\n");
		printf("%ld, %d _ %ld, %d\n", size, (*pile_a)[0], size_b, (*pile_b)[0]);
		j--;
	}
	return (size);
}

size_t	intel_tri_b(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t		size_b;
	int			pivot;

	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	ft_putstr("pb\n");
	return (size);
}

size_t	intel_tri_a(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	if (size_b == 1)
	{
		ft_push_b(argc, size, &(*pile_b), &(*pile_a));
		ft_putstr("pb\n");
		return (size);
	}
	size_b = argc - size - 1;
	ft_rotate(size_b, &(*pile_b));
	ft_putstr("rb\n");
	return (size);
}
