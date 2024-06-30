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

void print_stack(t_list *stack)
{
    t_list *current = stack;

    while (current != NULL)
    {
        printf("%d\n", current->content);
        current = current->next;
    }
}

t_list *get_bignode(t_list **a)
{
	t_list *curr;
	t_list *bignode;

	curr = *a;
	bignode = curr;
	while(curr)
	{
		if (bignode->content < curr->content)
			bignode = curr;
		curr = curr->next;
	}
	return (bignode);
}

void sort_three(t_list **a)
{
	t_list *bignode;

	bignode = get_bignode(a);
	if (bignode == *a)
		ra(a);
	else if (bignode == (*a)->next)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void sort_four(t_list **a, t_list **b)
{
	t_list *bignode;

	bignode = get_bignode(a);
	if (bignode == (*a)->next) //2nd
		ra(a);
	else if (bignode == (*a)->next->next) //3rd
	{
		ra(a);
		ra(a);
	}
	else if (bignode == (*a)->next->next->next) //last
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	ra(a);
}

// void sort_five(t_list **a, t_list **b)
// {

// }

void sort(t_list **a, t_list **b, t_data *data)
{
	if (data->count == 2 && (*a)->content > (*a)->next->content)
		rra(a);
	else if (data->count == 3)
		sort_three(a);
	else if (data->count == 4)
		sort_four(a, b);
	printf("-------\n");
	print_stack(*a);
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