/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_protocol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:16:44 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/03 06:42:24 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "pushswap.h"

size_t	intel_one(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	if ((*pile_a)[0] < (argc / 2))
	{
		size = ft_push_a(argc, size, &(*pile_a), &(*pile_b));
		ft_putstr("pa\n");
		return (size);
	}
	if ((*pile_a)[0] >= (argc / 2))
	{
		ft_rotate(size, &(*pile_a));
		ft_putstr("ra\n");
		return (size);
	}
}

size_t	intel_two_b(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t		size_b;
	int			pivot;

	pivot = (argc / 2) - (argc % 2);
	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	ft_putstr("pb\n");
	if (*pile_a[0] <= pivot / 2)
	{
		ft_rotate(size, &(*pile_a));
		ft_putstr("ra\n");
	}
	return (size);
}

size_t	intel_two_a(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	if (size_b == 1)
	{
		ft_push_b(argc, size, &(*pile_b), &(*pile_a));
		ft_putstr("pb\n");
		return (size);
	}
	ft_rotate(size_b, &(*pile_b));
	ft_putstr("rb\n");
	return (size);
}

int	intel_tri(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		tmp;

	size_b = argc - size - 1;
	while ((*pile_a)[0] < (argc / 2) - 1)
	{
		ft_rotate(size, &(*pile_a));
		ft_putstr("ra\n");
		tmp = (*pile_a)[0];
	}
	ft_rotate(size, &(*pile_a));
	ft_putstr("ra\n");
	return (tmp);
}

size_t	last_tri(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;
	int		last;
	int		i;

	i = argc / 2;
	size_b = argc - size - 1;
	last = size + size_b;
	while (size_b > 15)
	{
		printf("%d, %ld, %ld\n", (*pile_b)[0], size_b, size);
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
		else if ((*pile_b[0]) != last || (*pile_b[0] != i))
		{
			size = intel_tri_a(argc, size, &(*pile_a), &(*pile_b));
		}
		size_b = argc - size - 1;
		printf("%d, %ld, %ld\n", (*pile_b)[0], size_b, size);
	}
	return (size);
}
