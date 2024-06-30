/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:23:01 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:42:54 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list *smolnode;

	smolnode = get_smolnode(a);
	if (smolnode == (*a)->next) //2nd
		ra(a);
	else if (smolnode == (*a)->next->next) //3rd
	{
		ra(a);
		ra(a);
	}
	else if (smolnode == (*a)->next->next->next) //last
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void sort_five(t_list **a, t_list **b)
{
	t_list *smolnode;

	t_list *curr = *a;
	set_index(a);
	while (curr)
	{
		printf("index of %d is %d\n", curr->content, curr->index);
		curr = curr->next;
	}
	smolnode = get_smolnode(a);
	if (smolnode->index <= 2)
	{
		while(smolnode != *a)
			ra(a);
	}
	else
		while(smolnode != *a)
			rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void sort(t_list **a, t_list **b, t_data *data)
{
	if (data->count == 2 && (*a)->content > (*a)->next->content)
		rra(a);
	else if (data->count == 3)
		sort_three(a);
	else if (data->count == 4)
		sort_four(a, b);
	else if (data->count == 5)
		sort_five(a, b);
	printf("-------\n");
	print_stack(*a);
}

