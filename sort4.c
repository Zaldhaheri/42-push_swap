/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:07:38 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/07/04 21:33:29 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_list **a, t_list **b, t_data *data, int flag)
{
	data->max = get_bignode(b);
	data->min = get_smolnode(a);
	data->asize = ft_lstsize(*a);
	data->bsize = ft_lstsize(*b);
	data->amid = data->asize / 2;
	data->bmid = data->bsize / 2;
	if (flag)
	{
		set_targetnodea(a, b, data->max);
		set_totalcost(a, b);
		data->lowcost = get_lowcost(a);
	}
	else
	{
		set_targetnodeb(a, b, data->min);
		set_totalcost(b, a);
		data->lowcost = get_lowcost(b);
	}
}

void	turk1(t_list **a, t_list **b, t_data *data)
{
	pb(a, b);
	pb(a, b);
	stack_init(a, b, data, 1);
	while (data->asize > 3)
	{
		rot_turkab(a, b, data);
		turk2(a, b, data);
		pb(a, b);
		stack_init(a, b, data, 1);
	}
	sort_three(a);
	while (ft_lstsize(*b) > 0)
	{
		stack_init(a, b, data, 0);
		rot_turkba(a, b, data);
		turk3(a, b, data);
		pa(a, b);
	}
	mintop(a);
}

void	turk2(t_list **a, t_list **b, t_data *data)
{
	while (*a != data->lowcost)
	{
		if (data->lowcost->index < data->amid)
			ra(a);
		else
			rra(a);
	}
	while (*b != data->lowcost->targetnode)
	{
		if (data->lowcost->targetnode->index < data->bmid)
			rb(b);
		else
			rrb(b);
	}
}

void	turk3(t_list **a, t_list **b, t_data *data)
{
	while (*b != data->lowcost)
	{
		if (data->lowcost->index < data->bmid)
			rb(b);
		else
			rrb(b);
	}
	while (*a != data->lowcost->targetnode)
	{
		if (data->lowcost->targetnode->index < data->amid)
			ra(a);
		else
			rra(a);
	}
}
