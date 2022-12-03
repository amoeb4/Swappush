/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:28:10 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/02 00:35:06 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	*ft_init_a(size_t size, char **argv, int **pile_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	*pile_a = malloc(sizeof(int) * size);
	while (i < size + 1)
	{
		(*pile_a)[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (*pile_a);
}

int	*ft_init_b(size_t size, char **argv, int **pile_b)
{
	int	i;

	i = 0;
	*pile_b = malloc(sizeof(int) * size);
	while (i < size)
	{
		(*pile_b)[i] = '\0';
		i++;
	}
	return (*pile_b);
}

void	ft_indexing(size_t size, int **pile_a)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		k = size;
		while (j < size)
		{
			if ((*pile_a)[j] > (*pile_a)[i])
				k--;
			j++;
		}
		tmp[i] = k;
		i++;
	}
	(*pile_a) = tmp;
}
