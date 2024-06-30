/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:24:08 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:24:08 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sorted(t_list **a)
{
	t_list *curr;

	curr = *a;
	while(curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	printf("sorted");
	return (1);
}

int check_dup(t_data *data, int x, int check)
{
	int i;

	i = -1;
	while(++i < x)
		if (check == data->avnum[i])
			return (0);
	return (1);
}

int	is_valid(char *av[], t_data *data)
{
	if (av[data->i][0] == 0)
		data->flag = 0;
	while (av[data->i][data->j] == ' ')
		data->j++;
	if (av[data->i][data->j] >= '0' && av[data->i][data->j] <= '9')
		data->flag = 1;
	else if ((av[data->i][data->j] == '-' || av[data->i][data->j] == '+') &&
			(av[data->i][data->j + 1] >= '0' &&
			av[data->i][data->j + 1] <= '9'))
	{
		data->flag = 1;
		if (data->j != 0 && av[data->i][data->j - 1] != ' ')
			data->flag = 0;
		data->j++;
	}
	while (av[data->i][data->j + 1] == ' ')
		data->j++;
	return (data->flag);
}

int	checker(char *av[], t_data *data)
{
	data->i = 1;
	while (av[data->i])
	{
		data->j = 0;
		if (av[data->i][0] == 0)
			return (0);
		while (av[data->i][data->j])
		{
			data->flag = 0;
			if (!is_valid(av, data))
				return (0);
			data->j++;
		}
		data->i++;
	}
	return (1);
}
