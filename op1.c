#include "push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

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
