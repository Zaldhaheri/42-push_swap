#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	size_t	length;

	length = 0;
	while (lst)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}