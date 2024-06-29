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
	t_list *a_stack = NULL;
	t_list *b_stack;

	if (ac == 1 || !checker(av, &data))
		ft_putstr("Error\n");
	else
		{
			data.avstr = join_strings(av);
			data.avsplit = ft_split(data.avstr, ' ', &data);
			join_nums(&data);
			a_stack = makestack(&data, a_stack);
			b_stack = NULL;
			print_stack(a_stack);
			rra(&a_stack);
			printf("a\n");
			print_stack(a_stack);
			printf("b\n");
			print_stack(b_stack);
			freeing(data.avstr, data.avsplit, data.avnum, &data);
			ft_lstclear(&a_stack, free);
			ft_lstclear(&b_stack, free);
		}
	return (0);
}