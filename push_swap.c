/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:22:42 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:22:42 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_data	data;
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		exit (0);
	else if (!checker(av, &data))
		freexit(NULL, NULL, NULL, NULL);
	else
	{
		data.avstr = join_strings(av);
		data.avsplit = ft_split(data.avstr, ' ', &data);
		join_nums(&data);
		a = NULL;
		b = NULL;
		a = makestack(&data, a);
		if (!check_sorted(&a))
			sort(&a, &b, &data);
		if (check_sorted(&a))
			printf("sorted\n");
		freeing(data.avstr, data.avsplit, data.avnum, &data);
		ft_lstclear(&a, free);
		ft_lstclear(&b, free);
	}
}
