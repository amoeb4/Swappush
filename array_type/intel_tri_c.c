/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_tri_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 06:01:36 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/06 19:26:36 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

size_t	intel_tri_c(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	size_b = argc - size - 1;
	ft_rotate(size, &(*pile_a));
	ft_putstr("pa\nra\n");
	return (size);
}

int	intel_last(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		tmp;

	size_b = argc - size - 1;
	while ((*pile_a)[0] != 1)
	{
		ft_rotate(size, &(*pile_a));
		ft_putstr("ra\n");
	}
	return (size);
}

int	check_pos_b(size_t size_b, int **pile_b, int needle, int needlow)
{
	int		i;

	i = 0;
	while (i < size_b / 2)
	{
		if ((*pile_b)[i] == needlow)
			return (1);
		i++;
	}
	while (i >= size_b / 2)
	{
		if ((*pile_b)[i] == needlow)
			return (2);
		i++;
	}
	return (2);
}

size_t	intel_first(int argc, size_t size, int **pile_b, int needle)
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
	else
	{
		ft_reverse_rotate(size_b - 1, &(*pile_b));
		size_b = argc - size - 1;
		ft_putstr("rrb\n");
		return (size);
	}
}

int	is_lowest(int argc, size_t size, int **pile_b)
{
	int		i;
	int		tmp;
	size_t	size_b;

	tmp = argc;
	i = 0;
	size_b = argc - size - 1;
	while (i < size_b && size_b > 1)
	{
		if ((*pile_b)[i] < tmp)
			tmp = (*pile_b)[i];
		i++;
	}
	return (tmp);
}
