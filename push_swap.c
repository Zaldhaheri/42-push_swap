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

void set_targetnodeb(t_list **a, t_list **b, t_list *min)//target closest biggest number
{
	t_list *curr1;
	t_list *curr2;
	long	num;
	
	curr2 = *b;
	while(curr2)
	{
		curr1 = *a;
		curr2->targetnode = min;
		num = LONG_MAX;
		while(curr1)
		{
			if (num > curr1->content - curr2->content && curr1->content - curr2->content > 0)//bignum > 6 - 5 = 1 True & 6 > 0 False
			{
				num = curr1->content - curr2->content;
				curr2->targetnode = curr1;
			}
			curr1 = curr1->next;
		}
		curr2 = curr2->next;
	}
}

void set_targetnodea(t_list **a, t_list **b, t_list *max) //target closest smaller number
{
	t_list *curr1;
	t_list *curr2;
	long num;

	curr1 = *a;
	while(curr1)
	{
		curr2 = *b;
		curr1->targetnode = max;
		num = LONG_MIN;
		while(curr2)
		{
			// if (curr1->targetnode->content > curr2->content && curr1->content > curr2->content)
			// 	curr1->targetnode = curr2;
			if (num < curr2->content - curr1->content && curr2->content < curr1->content)
			{
				num = curr2->content - curr1->content;
				curr1->targetnode = curr2;
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
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

void mintop(t_list **a)
{
	t_list *min;
	int mid;
	int i;

	i = 0;
	mid = ft_lstsize(*a) / 2;
	set_index(a);
	set_cost(a);
	min = get_smolnode(a);
	while(i < min->cost)
	{
		if (min->index < mid)
			ra(a);
		else
			rra(a);
		i++;
	}
}

void turk3(t_list **a, t_list **b)
{
	t_list *lowcost;
	int mid;
	int i;

	i = 0;
	mid = ft_lstsize(*b) / 2;
	lowcost = get_lowcost(b);
	while(*b != lowcost)
	{
		if (lowcost->index < mid)
			rb(b);
		else
			rrb(b);
		i++;
	}
	i = 0;
	mid = ft_lstsize(*a) / 2;
	while(*a != lowcost->targetnode)
	{
		if (lowcost->targetnode->index < mid)
			ra(a);
		else
			rra(a);
		i++;
	}
}

void turk2(t_list **a, t_list **b)
{
	t_list *lowcost;
	int mid;
	int i;

	i = 0;
	mid = ft_lstsize(*a) / 2;
	lowcost = get_lowcost(a);
	while(*a != lowcost)
	{
		if (lowcost->index < mid)
			ra(a);
		else
			rra(a);
		i++;
	}
	i = 0;
	mid = ft_lstsize(*b) / 2;
	while(*b != lowcost->targetnode)
	{
		if (lowcost->targetnode->index < mid) //index above mid ra, else rra
			rb(b); //last becomes first
		else
			rrb(b); //first becomes last
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
		set_targetnodea(a, b, max);
		set_totalcost(a, b);
		turk2(a, b);
		pb(a, b);
	}
	sort_three(a);
	while(ft_lstsize(*b) > 0)
	{
		min = get_smolnode(a);
		set_targetnodeb(a, b, min);
		set_totalcost(b, a);
		turk3(a, b);
		pa(a, b);
	}
	mintop(a);
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
			// printf("a-----\n");
			// print_stack(a);
			// printf("b-----\n");
			// print_stack(b);
			freeing(data.avstr, data.avsplit, data.avnum, &data);
			if (check_sorted(&a))
				printf("sorted\n");
			ft_lstclear(&a, free);
			ft_lstclear(&b, free);
		}
	return (0);
}