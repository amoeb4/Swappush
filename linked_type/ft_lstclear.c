/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:44:39 by dafranco          #+#    #+#             */
/*   Updated: 2022/10/18 05:50:27 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buff;

	if (!del)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		buff = *lst;
		*lst = buff->next;
		free(buff);
	}
	*lst = NULL;
}
