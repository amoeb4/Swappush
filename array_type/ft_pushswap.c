/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:02:46 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/13 01:11:30 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>
#include"pushswap.h"

int	ft_checkdouble(int argc, char **argv)
{
	int	j;
	int	i;
	int	duplicates;

	i = 1;
	duplicates = 0;
	while (i < argc)
	{
		j = (i + 1);
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_issorted(int argc, char **pile_a)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(pile_a[i]) > ft_atoi(pile_a[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1 || ft_checkdouble(argc, argv) == 1 || ft_isint(argv[i]) > 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	while (i < argc)
	{
		if (is_strdigit(argv[i]) == 1)
		{
			ft_putstr("Err0r\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				*pile_a;
	int				*pile_b;
	size_t			size_b;
	size_t			size;

	if (ft_valid(argc, argv) > 0)
		return (1);
	if (ft_issorted(argc, argv) == 0)
		return (0);
	size = argc - 1;
	pile_a = ft_init_a(size, argv, &pile_a);
	pile_b = ft_init_b(size, argv, &pile_b);
	ft_indexing(size, &pile_a);
	size_b = argc - size - 1;
	size = ft_call(argc, size, &pile_a, &pile_b);
	size_b = argc - size - 1;
	int i = 0;
	printf("_________\n| A | B |\n|---|---|\n");
	while (i < size_b || i < size)
	{
		printf("| %d | %d |\n", pile_a[i], pile_b[i]);
		i++;
	}
	printf("|___|___|\n argc = %d\n step 3", argc);
	free(pile_a);
	free(pile_b);
	return (0);
}
