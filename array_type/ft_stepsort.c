/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stepsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:32:44 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/10 18:50:30 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

size_t	ft_one(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		spike;
	int		nb;

	spike = ft_spikes(argc, size, &(*pile_a));
	nb = (*pile_a)[spike];
	size_b = argc - size - 1;
	while ((*pile_a)[0] != nb && spike > 0)
	{
		if (argc - spike <= argc / 2 + (argc % 2) - 1)
		{
			ft_reverse_rotate(size - 1, &(*pile_a));
			ft_putstr("rra\n");
		}
		if (argc - spike > argc / 2 + (argc % 2) - 1)
		{
			ft_rotate(size, &(*pile_a));
			ft_putstr("ra\n");
		}
		size_b = argc - size - 1;
	}
	if (ft_pile_sorted(size, &(*pile_a)) == 0)
		return (size);
	size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
	ft_putstr(">pb\n");
	return (size);
}

size_t	xintel_one(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		ct;

	ct = (*pile_a)[0] - (*pile_b)[0];
	if (ft_pile_sorted(size, &(*pile_a)) == 0)
		return (size);
	size_b = argc - size - 1;
	while ((*pile_b)[0] != (*pile_a)[0] - 1)
	{
		if (ct > argc / 2 + (argc % 2) - 1)
		{
			ft_rotate(size, &(*pile_a));
			ft_putstr("ra\n");
		}
		if (ct < argc / 2 + (argc % 2) - 1)
		{
			ft_reverse_rotate(size - 1, &(*pile_a));
			ft_putstr("rra\n");
		}
		size_b = argc - size - 1;
	}
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	ft_putstr("pa\n");
	return (size);
}

size_t	ft_resort(int argc, size_t size, int **pile_a)
{
	int	pos;

	pos = (*pile_a)[0];
	if (ft_pile_sorted(size, &(*pile_a)) == 0)
		return (size);
	while ((*pile_a)[0] != 1)
	{
		if (pos >= argc / 2 + (argc % 2) - 1)
		{
			ft_rotate(size, &(*pile_a));
			ft_putstr("ra\n");
		}
		if (pos < argc / 2 + (argc % 2) - 1)
		{
			ft_reverse_rotate(size - 1, &(*pile_a));
			ft_putstr("rra\n");
		}
	}
	return (size);
}

int	ft_spikes(int argc, size_t size, int **pile_a)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	if (ft_pile_sorted(size, &(*pile_a)) == 1)
	{
		if (ft_specials(argc, size, &(*pile_a)) == 1)
			return (0);
		while (i < size - 1)
		{
			if ((*pile_a)[i + 1] < (*pile_a)[i])
			{
				pos = i + 1;
				if ((*pile_a)[i + 1] > ((*pile_a)[i - 1]))
					pos = i;
			}
			i++;
		}
	}
	return (pos);
}

int	ft_specials(int argc, size_t size, int **pile_a)
{
	if ((*pile_a)[0] == argc - 1)
	{
		ft_rotate(size, &(*pile_a));
		ft_putstr("ra\n");
		return (1);
	}
	if ((*pile_a)[1] == 1)
	{
		ft_swap(*pile_a);
		ft_putstr("sa\n");
		return (1);
	}
	return (0);
}
