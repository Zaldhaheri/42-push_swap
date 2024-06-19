/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:18:52 by marvin            #+#    #+#             */
/*   Updated: 2024/06/19 14:18:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid(char *av[], t_data *data)
{
	if (av[data->i][0] == 0)
		data->flag = 0;
	while(av[data->i][data->j] == ' ')
		data->j++;
	if (av[data->i][data->j] >= '0' && av[data->i][data->j] <= '9')
		data->flag = 1;
	else if ((av[data->i][data->j] == '-' || av[data->i][data->j] == '+') && 
			(av[data->i][data->j + 1] >= '0' && av[data->i][data->j + 1] <= '9'))
	{
		data->flag = 1;
		if (data->j != 0 && av[data->i][data->j - 1] != ' ')
			data->flag = 0;
		data->j++;
	}
	while(av[data->i][data->j + 1] == ' ')
		data->j++;
	return(data->flag);
}

int checker(int ac, char *av[], t_data *data)
{
	(void)ac;

	data->i = 1;
	while (av[data->i])
	{
		data->j = 0;
		if (av[data->i][0] == 0)
			return (0);
		while (av[data->i][data->j])
		{
			data->flag = 0;
			if(!is_valid(av, data))
				return(0);
			data->j++;
		}
		data->i++;
	}
	return (1);
}
