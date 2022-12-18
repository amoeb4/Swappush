/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_protocol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:16:44 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/10 17:19:30 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "pushswap.h"

size_t	intel_one(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	if ((*pile_a)[0] <= (argc / 2) + (argc % 2) - 1)
	{
		size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
		ft_putstr("pb\n");
		if ((*pile_b)[0] <= (argc / 4) && size_b > 1)
		{
			size_b = argc - size - 1;
			ft_rotate(size_b, &(*pile_b));
			ft_putstr("rb\n");
		}
		return (size);
	}
	if ((*pile_a)[0] > (argc / 2) + (argc % 2) - 1)
	{
		ft_rotate(size, &(*pile_a));
		ft_putstr("ra\n");
		return (size);
	}
	return (size);
}

size_t	intel_two_b(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t		size_b;

	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	size_b = argc - size - 1;
	ft_rotate(size, &(*pile_a));
	size_b = argc - size - 1;
	ft_putstr("pa\nra\n");
	return (size);
}

size_t	intel_two_a(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	size_b = argc - size - 1;
	ft_putstr("pa\n");
	return (size);
}

size_t	intel_tri(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t		size_b;
	int			pivot;

	pivot = (argc - 1) - (*pile_a)[size - 1] / 2;
	size_b = argc - size - 1;
	if ((*pile_a)[0] >= pivot || (size_b == 0))
	{
		size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
		size_b = argc - size - 1;
		ft_putstr("pb\n");
		return (size);
	}
	if ((*pile_a)[0] < pivot)
	{
		size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
		size_b = argc - size - 1;
		ft_rotate(size_b, &(*pile_b));
		size_b = argc - size - 1;
		ft_putstr("pb\nrb\n");
		return (size);
	}
	return (size);
}

size_t	intel_tri_b(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t		size_b;
	int			pivot;

	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	ft_putstr("pa\n");
	return (size);
}
