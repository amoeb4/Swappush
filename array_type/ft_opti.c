/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:26:58 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/10 17:18:05 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		k;
	char		*str;

	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	k = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[k + i] = '\0';
	return (str);
}

char	*ft_rewrite_rotate(char *str)
{
	int		i;
	int		j;
	char	*pattern1;
	char	*pattern2;
	char	*newstr;

	i = 0;
	j = 0;
	pattern1 = "ra\nrb";
	pattern2 = "rb\nra";
	while (str[i])
	{
		if (str[i] == pattern1[j])
		{
			j++;
			if (j == 5)
				j = 0;
				newstr[i] = '1';
		}
		i++;
	}
	return (newstr);
}

char	*ft_rewrite_reverse(char *str)
{
	int		i;
	int		j;
	char	*pattern1;
	char	*pattern2;
	char	*newstr;

	i = 0;
	j = 0;
	pattern1 = "rra\nrrb";
	pattern2 = "rrb\nrra";
	while (str[i])
	{
		if (str[i] == pattern1[j])
		{
			j++;
			if (j == 7)
				j = 0;
				newstr[i] = '1';
		}
		i++;
	}
	return (newstr);
}

//char *ft_patch(char *str)
//{
//
//}
