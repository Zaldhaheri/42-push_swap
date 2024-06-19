/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:54:09 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 11:54:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int num;
}   t_list;

typedef struct s_data
{
    int count;
    int i;
    int j;
    t_list head;
    t_list tail;
}   t_data;


//utils
void ft_putstr(char *s);

//checkers
int is_valid(char *av[], t_data *data);
int checker(int ac, char *av[], t_data *data);

#endif