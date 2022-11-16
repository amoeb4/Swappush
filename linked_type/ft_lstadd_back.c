/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:28:32 by dafranco          #+#    #+#             */
/*   Updated: 2022/11/16 04:56:36 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*content;

	if (lst && *lst)
	{
		content = *lst;
		while (content->next)
			content = content->next;
		content->next = new;
	}
	else if (lst)
		*lst = new;
}
