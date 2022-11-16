/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:47:28 by dafranco          #+#    #+#             */
/*   Updated: 2022/11/16 04:59:52 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_parser(t_stack *stack, int argc, char **argv, int start)
{
	int	i;
	int	*tmp;

	i = start;
	while (i < argc)
	{
		tmp = malloc(sizeof(int));
		*tmp = ft_atoi(argv[i]);
		ft_lstadd_back(stack->pile_a, tmp);
		i++;
	}
}
