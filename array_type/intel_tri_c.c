/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_tri_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 06:01:36 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/03 06:41:56 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

size_t	intel_tri_c(int argc, size_t size, int **pile_a, int **pile_b)
{
	size_t	size_b;

	size_b = argc - size - 1;
	size = ft_push_b(argc, size, &(*pile_b), &(*pile_a));
	size_b = argc - size - 1;
//	ft_rotate(size, &(*pile_a));
	ft_putstr("pb\nra\n");
	return (size);
}
