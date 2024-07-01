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

void set_index(t_list **a)
{
	int i;
	t_list *curr;

	i = 0;
	curr = *a;
	while(curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
}

t_list *get_bignode(t_list **a)
{
	t_list *curr;
	t_list *bignode;

	curr = *a;
	bignode = curr;
	while(curr)
	{
		if (bignode->content < curr->content)
			bignode = curr;
		curr = curr->next;
	}
	return (bignode);
}

t_list *get_smolnode(t_list **a)
{
	t_list *curr;
	t_list *smolnode;

	curr = *a;
	smolnode = curr;
	while(curr)
	{
		if (smolnode->content > curr->content)
			smolnode = curr;
		curr = curr->next;
	}
	return (smolnode);
}