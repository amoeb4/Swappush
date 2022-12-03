/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:24:20 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/02 04:21:34 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pushswap.h"
#include <stdio.h>

void	ft_rotate(size_t size, int **pile)
{
	int		i;
	int		temp;

	temp = (*pile)[0];
	i = 0;
	while (i < size - 1)
	{
		(*pile)[i] = (*pile)[i + 1];
		i++;
	}
	(*pile)[i] = temp;
}

void	ft_reverse_rotate(size_t size, int **pile)
{
	int		i;
	int		tmp;

	tmp = (*pile)[size];
	i = size;
	while (i > 0)
	{	
		(*pile)[i] = (*pile)[i - 1];
		i--;
	}
	(*pile)[0] = tmp;
}

void	ft_swap(int *pile_a)
{
	int	temp;

	temp = pile_a[0];
	pile_a[0] = pile_a[1];
	pile_a[1] = temp;
}

size_t	ft_push_a(int argc, size_t size, int **src, int **dest)
{
	size_t	size_b;

	size_b = (argc - size) - 1;
	(*dest)[size_b] = (*src)[0];
	ft_reverse_rotate(size_b, *&dest);
	size--;
	size_b = 0;
	while (size_b <= size)
	{
		(*src)[size_b] = (*src)[size_b + 1];
		size_b++;
	}
	return (size);
}

size_t	ft_push_b(int argc, size_t size, int **src, int **dest)
{
	size_t	size_b;
	int		i;

	size++;
	size_b = (argc - size) - 1;
	(*dest)[size] = (*src)[0];
	ft_reverse_rotate(size, *&dest);
	i = 0;
	while (i < size_b)
	{
		(*src)[i] = (*src)[i + 1];
		i++;
	}
	(*src)[size_b] = '\0';
	return (size);
}
