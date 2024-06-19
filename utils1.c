/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:12:28 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 12:12:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(char *s)
{
	if (!*s)
		return ;
    write(1, s, 1);
	ft_putstr(s + 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*r;

	i = 0;
	j = 0;
	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 3));
	if (!r)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	r[i++] = ' ';
	while (s2[j])
		r[i++] = s2[j++];
	r[i++] = ' ';
	r[i] = '\0';
	return (r);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *) malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}