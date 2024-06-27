/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:47:04 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/19 19:47:04 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
    void    *content;
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
    struct s_list *a_head;
    struct s_list *a_tail;
    struct s_list *b_head;
    struct s_list *b_tail;
}   t_data;

//utils
void ft_putstr(char *s);
int	ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c, t_data *data);

//list utils


//checkers
int is_valid(char *av[], t_data *data);
int checker(char *av[], t_data *data);
int check_dup(t_data *data, int x, int check);

//parsing
void freeing(char *str, char **string, int *nums, t_data *data);
void freexit(char *str, char **string, int *nums, char *msg, t_data *data);
char *join_strings(char *av[]);
void	join_nums(t_data *data);

#endif