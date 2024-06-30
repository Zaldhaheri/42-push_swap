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
//parsing
//inputing data as nodes in linked list
//stacks
//operations
//algorithm

void print_stack(t_list *stack)
{
    t_list *current = stack;

    while (current != NULL)
    {
        printf("%d\n", current->content);
        current = current->next;
    }
}

int main(int ac, char *av[])
{
	t_data data;
	t_list *a;
	t_list *b;

	if (ac == 1 || !checker(av, &data))
		ft_putstr("Error\n");
	else
		{
			data.avstr = join_strings(av);
			data.avsplit = ft_split(data.avstr, ' ', &data);
			join_nums(&data);
			a = NULL;
			b = NULL;
			a = makestack(&data, a);
			print_stack(a);
			if (!check_sorted(&a))
				sort(&a, &b, &data);
			freeing(data.avstr, data.avsplit, data.avnum, &data);
			ft_lstclear(&a, free);
			ft_lstclear(&b, free);
		}
	return (0);
}