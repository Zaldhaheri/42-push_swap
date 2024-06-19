/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:47:20 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/19 19:47:20 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//parsing
//inputing data as nodes in linked list
//stacks
//operations
//algorithm

char *join_strings(char *av[])
{
	int i;
	char *r;

	i = 1;
	r = ft_strdup("");
	while(av[i])
		r = ft_strjoin(r, av[i++]);
	return (r);
}

void	join_nums(t_data *data)
{
	int i;

	i = -1;
	data->avnum = (int *) malloc(sizeof(int) * data->count);
	while(++i <= data->count - 1)
	{
		data->avnum[i] = ft_atoi(data->avsplit[i]);
		printf("num: %d\n", data->avnum[i]);
		if (!check_dup(data, i, data->avnum[i]))
			printf("DUPLICATE\n"); //free shit exit
	}
}

int main(int ac, char *av[])
{
	t_data data;
	if (ac == 1 || !checker(av, &data))
		ft_putstr("Error\n");
	else
		{
			data.avstr = join_strings(av);
			ft_putstr("Pass\n");
			printf("strjoin : %s\n", data.avstr);
			data.avsplit = ft_split(data.avstr, ' ', &data);
			int i = 0;
			printf("count: %d\n", data.count);
			while (data.avsplit[i])
				printf("str: %s\n", data.avsplit[i++]);
			join_nums(&data);
		}
	return (0);
}