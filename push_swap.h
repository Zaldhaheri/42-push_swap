/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:22:55 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/06/30 22:22:55 by zaldhahe         ###   ########.fr       */
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
    int content;
    int index;
    int cost;
    int totalcost;
    struct s_list *targetnode;
    struct s_list *next;
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
}   t_data;

//test
void print_stack(t_list *stack);

//utils
void ft_putstr(char *s);
int	ft_atoi(const char *str, t_data *data);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c, t_data *data);

//list utils
t_list *ft_lstnew(int num);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

//checkers
int is_valid(char *av[], t_data *data);
int checker(char *av[], t_data *data);
int check_dup(t_data *data, int x, int check);
int check_sorted(t_list **a);

//parsing
void freeing(char *str, char **string, int *nums, t_data *data);
void freexit(char *str, char **string, int *nums, char *msg, t_data *data);
char *join_strings(char *av[]);
void	join_nums(t_data *data);
t_list *makestack(t_data *data, t_list *a_stack);

//operations
void sa(t_list **a);
void sb(t_list **b);
void ss(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
void pb(t_list **a, t_list **b);
void ra(t_list **a);
void rb(t_list **b);
void rr(t_list **a, t_list **b);
void rra(t_list **a);
void rrb(t_list **b);
void rrr(t_list **a, t_list **b);

//sort utils
void sort(t_list **a, t_list **b, t_data *data);
void sort_three(t_list **a);
void sort_four(t_list **a, t_list **b);
void sort_five(t_list **a, t_list **b);
void set_index(t_list **a);
t_list *get_bignode(t_list **a);
t_list *get_smolnode(t_list **a);
void turk1(t_list **a, t_list **b, t_data *data);

#endif