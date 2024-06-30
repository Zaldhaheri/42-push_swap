/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:24:01 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:24:01 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack)
{
    t_list *temp;

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    *stack = temp;
}

void sa(t_list **a)
{
    if (!(*a)->next)
        return ;
    swap(a);
    ft_putstr("sa\n");
}

void sb(t_list **b)
{
    if (!(*b)->next)
        return ;
    swap(b);
    ft_putstr("sb\n");
}

void ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    ft_putstr("ss\n");
}
