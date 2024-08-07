/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:23:38 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:23:38 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeing(char *str, char **string, int *nums, t_data *data)
{
	int	i;

	i = -1;
	if (str)
		free(str);
	if (string)
	{
		while (++i <= data->count - 1)
			free(string[i]);
		free(string);
	}
	if (nums)
		free(nums);
}

void	freexit(char *str, char **string, int *nums, t_data *data)
{
	freeing(str, string, nums, data);
	ft_putstr(ERROR_MSG);
	exit (1);
}

char	*join_strings(char *av[])
{
	int		i;
	char	*r;
	char	*temp;

	i = 1;
	r = ft_strdup("");
	while (av[i])
	{
		temp = r;
		r = ft_strjoin(r, av[i++]);
		free(temp);
	}
	return (r);
}

void	join_nums(t_data *data)
{
	int	i;

	i = -1;
	data->avnum = (int *) malloc(sizeof(int) * data->count);
	while (++i <= data->count - 1)
	{
		data->avnum[i] = ft_atoi(data->avsplit[i], data);
		if (!check_dup(data, i, data->avnum[i]))
			freexit(data->avstr, data->avsplit, data->avnum, data);
	}
}

t_list	*makestack(t_data *data, t_list *a_stack)
{
	t_list	*node;
	int		i;

	i = 0;
	while (i < data->count)
	{
		node = ft_lstnew(data->avnum[i]);
		if (!node)
		{
			ft_lstclear(&a_stack, free);
			freexit(NULL, NULL, data->avnum, data);
		}
		ft_lstadd_back(&a_stack, node);
		i++;
	}
	return (a_stack);
}
