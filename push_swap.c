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

void set_cost(t_list **a)
{
	t_list *curr;
	int count;
	int mid;

	set_index(a);
	count = ft_lstsize(*a);
	mid = count / 2;
	curr = *a;
	while(curr)
	{
		if (curr->index <= mid)
			curr->cost = curr->index;
		else
			curr->cost = count - curr->index;
		curr = curr->next;
	}
	printf("mid: %d\n", mid);
}


void set_totalcost(t_list **a, t_list **b)
{
	t_list *curr;

	curr = *a;
	set_cost(a);
	set_cost(b);
	while(curr)
	{
		curr->totalcost = curr->cost + curr->targetnode->cost;
		curr = curr->next;
	}
}

void set_targetnode(t_list **a, t_list **b, t_list *max)
{
	t_list *curr1;
	t_list *curr2;

	curr1 = *a;
	while(curr1)
	{
		curr2 = *b;
		curr1->targetnode = max;
		while(curr2)
		{
			if (curr1->targetnode->content > curr2->content && curr1->content > curr2->content)
				curr1->targetnode = curr2;
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
	curr1 = *a;
}

t_list *get_lowcost(t_list **a)
{
	t_list *curr;
	t_list *lowcost;

	curr = *a;
	lowcost = curr;
	while (curr)
	{
		if (lowcost->totalcost > curr->totalcost)
			lowcost = curr;
		curr = curr->next;
	}
	return (lowcost);
}

void turk2(t_list **a, t_list **b)
{
	t_list *lowcost;
	int mid;
	int i;

	i = 0;
	mid = ft_lstsize(*a) / 2;
	lowcost = get_lowcost(a);
	while(i < lowcost->cost)
	{
		if (lowcost->index < mid)
			ra(a);
		else
			rra(a);
		i++;
	}
	i = 0;
	mid = ft_lstsize(*b) / 2;
	while(i < lowcost->targetnode->cost)
	{
		if (lowcost->targetnode->index < mid)
			ra(b);
		else
			rra(b);
		i++;
	}
}

void turk1(t_list **a, t_list **b, t_data *data)
{
	(void)data;
	t_list *max;
	t_list *min;

	pb(a, b);
	pb(a, b);
	while(ft_lstsize(*a) > 3)
	{
		max = get_bignode(b);
		min = get_smolnode(b);
		set_targetnode(a, b, max);
		set_totalcost(a, b);
		turk2(a, b);
		pb(a, b);
	}
	sort_three(a);
	t_list *curr = *a;

	while (curr)
	{
		printf("%d cost: %d\n", curr->content, curr->cost);
		curr = curr->next;
	}
	printf("big node: %d, smolnode: %d\n", max->content, min->content);
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

int main(int ac, char *av[])
{
	t_data data;
	t_list *a;
	t_list *b;

	if (ac == 1)
		exit(0);
	else if (!checker(av, &data))
		ft_putstr("Error\n");
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
			printf("a-----\n");
			print_stack(a);
			printf("b-----\n");
			print_stack(b);
			freeing(data.avstr, data.avsplit, data.avnum, &data);
			ft_lstclear(&a, free);
			ft_lstclear(&b, free);
		}
	return (0);
}