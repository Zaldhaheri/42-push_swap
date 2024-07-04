/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:23:03 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:42:42 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_bignode(t_list **a)
{
	t_list	*curr;
	t_list	*bignode;

	curr = *a;
	bignode = curr;
	while (curr)
	{
		if (bignode->content < curr->content)
			bignode = curr;
		curr = curr->next;
	}
	return (bignode);
}

t_list	*get_smolnode(t_list **a)
{
	t_list	*curr;
	t_list	*smolnode;

	curr = *a;
	smolnode = curr;
	while (curr)
	{
		if (smolnode->content > curr->content)
			smolnode = curr;
		curr = curr->next;
	}
	return (smolnode);
}

t_list	*get_lowcost(t_list **a)
{
	t_list	*curr;
	t_list	*lowcost;

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

void	set_totalcost(t_list **a, t_list **b)
{
	t_list	*curr;

	curr = *a;
	set_cost(a);
	set_cost(b);
	while (curr)
	{
		curr->totalcost = curr->cost + curr->targetnode->cost;
		curr = curr->next;
	}
}

void	set_cost(t_list **a)
{
	t_list	*curr;
	int		count;
	int		mid;

	set_index(a);
	count = ft_lstsize(*a);
	mid = count / 2;
	curr = *a;
	while (curr)
	{
		if (curr->index <= mid)
			curr->cost = curr->index;
		else
			curr->cost = count - curr->index;
		curr = curr->next;
	}
}
