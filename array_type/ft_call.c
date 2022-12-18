/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:22:19 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/13 03:27:16 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

size_t	ft_call_one(int argc, size_t size, int **pile_a, int **pile_b)
{
	if (argc == 3)
	{
		ft_swap(*pile_a);
		ft_putstr("sa\n");
	}
	if (argc == 4)
		size = ft_self_sort(size, &(*pile_a));
	if (argc == 5)
		size = ft_more(argc, size, &(*pile_a), &(*pile_b));
	return (size);
}

size_t	ft_call_two(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	if (ft_pile_sorted(size, &(*pile_a)) == 1
		|| ft_pile_sorted(size, &(*pile_a)) == 2)
	{
		size = ft_one(argc, size, &(*pile_a), &(*pile_b));
		size_b = argc - size - 1;
		size = xintel_one(argc, size, &(*pile_a), &(*pile_b));
		size_b = argc - size - 1;
		size = ft_resort(argc, size, &(*pile_a));
		size_b = argc - size - 1;
	}
	if (ft_pile_sorted(size, &(*pile_a)) == 0)
		return (size);
	else
		ft_call(argc, size, &(*pile_a), &(*pile_b));
	return (size);
}

size_t	ft_call_thre(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	size = ft_step_one(argc, size, &(*pile_a), &(*pile_b));
	size_b = argc - size - 1;
	size = ft_step_two(argc, size, &(*pile_a), &(*pile_b));
	size_b = argc - size - 1;
	if (ft_pile_sorted(size, &(*pile_a)) == 0)
		return (size);
	size = ft_step_thre(argc, size, &(*pile_a), &(*pile_b));
	size_b = argc - size - 1;
	size = last_tri(argc, size, &(*pile_a), &(*pile_b));
	size_b = argc - size - 1;
	size = intel_last(argc, size, &(*pile_a), &(*pile_b));
	size_b = argc - size - 1;
	return (size);
}

size_t	ft_call(int argc, size_t size, int **pile_a, int **pile_b)
{
	if (argc < 6)
	{
		size = ft_call_one(argc, size, &(*pile_a), &(*pile_b));
		return (size);
	}
	if (argc == 6)
	{
		size = sort_five(argc, size, &(*pile_a), &(*pile_b));
		return (size);
	}
	if (argc > 6 && ft_pile_sorted(argc, &(*pile_a)) <= 2)
	{
		size = ft_call_two(argc, size, &(*pile_a), &(*pile_b));
		return (size);
	}
	else
		size = ft_call_thre(argc, size, &(*pile_a), &(*pile_b));
	return (size);
}
