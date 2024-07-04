/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:07:36 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/07/04 21:32:19 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_turkab(t_list **a, t_list **b, t_data *data)
{
	while (*a != data->lowcost && *b != data->lowcost->targetnode)
	{
		if (data->lowcost->index < data->amid
			&& data->lowcost->targetnode->index < data->bmid)
			rr(a, b);
		else if (data->lowcost->index >= data->amid
			&& data->lowcost->targetnode->index >= data->bmid)
			rrr(a, b);
		else
			break ;
	}
}

void	rot_turkba(t_list **a, t_list **b, t_data *data)
{
	while (*b != data->lowcost && *a != data->lowcost->targetnode)
	{
		if (data->lowcost->index < data->amid
			&& data->lowcost->targetnode->index < data->bmid)
			rr(a, b);
		else if (data->lowcost->index >= data->amid
			&& data->lowcost->targetnode->index >= data->bmid)
			rrr(a, b);
		else
			break ;
	}
}

void	mintop(t_list **a)
{
	t_list	*min;
	int		mid;
	int		i;

	i = 0;
	mid = ft_lstsize(*a) / 2;
	set_index(a);
	set_cost(a);
	min = get_smolnode(a);
	while (i < min->cost)
	{
		if (min->index < mid)
			ra(a);
		else
			rra(a);
		i++;
	}
}

void	set_targetnodea(t_list **a, t_list **b, t_list *max)
{
	t_list	*curr1;
	t_list	*curr2;
	long	num;

	curr1 = *a;
	while (curr1)
	{
		curr2 = *b;
		curr1->targetnode = max;
		num = LONG_MIN;
		while (curr2)
		{
			if (num < curr2->content - curr1->content
				&& curr2->content < curr1->content)
			{
				num = curr2->content - curr1->content;
				curr1->targetnode = curr2;
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
}

void	set_targetnodeb(t_list **a, t_list **b, t_list *min)
{
	t_list	*curr1;
	t_list	*curr2;
	long	num;

	curr2 = *b;
	while (curr2)
	{
		curr1 = *a;
		curr2->targetnode = min;
		num = LONG_MAX;
		while (curr1)
		{
			if (num > curr1->content - curr2->content
				&& curr1->content > curr2->content)
			{
				num = curr1->content - curr2->content;
				curr2->targetnode = curr1;
			}
			curr1 = curr1->next;
		}
		curr2 = curr2->next;
	}
}
