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
    struct s_list *next;
    struct s_list *prev;
}   t_list;

typedef struct s_data
{
    int count;
    int i;
    int j;
    int flag;
    char *avstr;
    char **avsplit;
    int *avnum;
    struct s_list *head;
    struct s_list *tail;
}   t_data;


//utils
void ft_putstr(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);

//checkers
int is_valid(char *av[], t_data *data);
int checker(int ac, char *av[], t_data *data);

#endif