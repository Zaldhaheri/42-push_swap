/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:23:50 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:23:50 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **from, t_list **to)
{
    t_list *temp;

    temp = (*from);
    (*from) = (*from)->next;
    temp->next = (*to);
    (*to) = temp;
}

void pa(t_list **a, t_list **b)
{
    if (!(*b))
        return ;
    push(b, a);
    ft_putstr("pa\n");
}

void pb(t_list **a, t_list **b)
{
    if (!(*a))
        return ;
    push(a, b);
    ft_putstr("pb\n");
}