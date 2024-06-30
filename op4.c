/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:23:43 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:23:43 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrot(t_list **stack)
{
    t_list *temp;

    temp = *stack;
    while (temp->next->next)
        temp = temp->next;
    temp->next->next = *stack;
    *stack = temp->next; 
    temp->next = NULL;
}

void rra(t_list **a)
{
    if (!(*a)->next)
        return ;
    rrot(a);
    ft_putstr("rra\n");
}

void rrb(t_list **b)
{
    if (!(*b)->next)
        return ;
    rrot(b);
    ft_putstr("rrb\n");
}

void rrr(t_list **a, t_list **b)
{
    if (!(*a)->next)
        return ;
    rrot(a);
    if (!(*b)->next)
        return ;
    rrot(b);
    ft_putstr("rrr\n");
}
