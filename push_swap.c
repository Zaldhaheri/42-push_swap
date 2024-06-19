/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:53:28 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 11:53:28 by marvin           ###   ########.fr       */
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

int main(int ac, char *av[])
{
	t_data data;
	if (ac == 1 || !checker(ac, av, &data))
		ft_putstr("Error\n");
	else
		{
			data.avstr = join_strings(av);
			ft_putstr("Pass\n");
			printf("%s\n", data.avstr);
			data.avsplit = ft_split(data.avstr, ' ');
			int i = 0;
			while (data.avsplit[i])
				printf("%s\n", data.avsplit[i++]);

		}
	return (0);
}