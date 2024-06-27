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

void makestack(t_data *data)
{

}

int main(int ac, char *av[])
{
	t_data data;
	t_list *a_stack;
	t_list *b_stack;

	if (ac == 1 || !checker(av, &data))
		ft_putstr("Error\n");
	else
		{
			data.avstr = join_strings(av);
			data.avsplit = ft_split(data.avstr, ' ', &data);
			freeing(data.avstr, NULL, NULL, NULL);
			join_nums(&data);
			freeing(NULL, data.avsplit, data.avnum, &data);
		}
	return (0);
}
