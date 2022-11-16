/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:18:56 by dafranco          #+#    #+#             */
/*   Updated: 2022/11/16 06:01:28 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "stdio.h"

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
	int	*pile_a;
	int	*pile_b;
	int	i;

	i = 0;
	if (ft_valid(argc, argv) > 0)
		return (1);
	if (ft_issorted(argc, argv) == 0)
		return (0);

	printf("_________\n| A | B |\n|---|---|\n");
	while (pile_a[i] || pile_b[i])
	{
		printf("| %d | %d |\n", pile_a[i], pile_b[i]);
		i++;
	}
	printf("|___|___|");
	return (0);
}
