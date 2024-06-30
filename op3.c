/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:23:47 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:23:47 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rot(t_list **stack)
{
    t_list *temp;

    temp = ft_lstlast(*stack);
    temp->next = (*stack);
    *stack = (*stack)->next;
    temp = temp->next;
    temp->next = NULL;
}

void ra(t_list **a)
{
    if (!(*a)->next)
        return ;
    rot (a);
    ft_putstr("ra\n");
}

void rb(t_list **b)
{
    if (!(*b)->next)
        return ;
    rot (b);
    ft_putstr("rb\n");
}

void rr(t_list **a, t_list **b)
{
    if (!(*a)->next)
        return ;
    rot (a);
    if (!(*b)->next)
        return ;
    rot (b);
    ft_putstr("rr\n");
}
