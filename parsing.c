#include "push_swap.h"

void freeing(char *str, char **string, int *nums, t_data *data)
{
	int i;

	i = -1;
	if (str)
		free(str);
	if (string)
	{
		while (++i <= data->count - 1)
			free(string[i]);
		free(string); //loop through and free double array
	}
	if (nums)
		free(nums);
}

void freexit(char *str, char **string, int *nums, char *msg, t_data *data)
{
	freeing(str, string, nums, data);
	if (msg)
		ft_putstr(msg);
	exit (1);
}

char *join_strings(char *av[])
{
	int i;
	char *r;
	char *temp;

	i = 1;
	r = ft_strdup("");
	while(av[i])
	{
		temp = r;
		r = ft_strjoin(r, av[i++]);
		free(temp);
	}
	return (r);
}

void	join_nums(t_data *data)
{
	int i;

	i = -1;
	data->avnum = (int *) malloc(sizeof(int) * data->count);
	while(++i <= data->count - 1)
	{
		data->avnum[i] = ft_atoi(data->avsplit[i], data);
		if (!check_dup(data, i, data->avnum[i]))
			freexit(NULL, data->avsplit, data->avnum, "Error\n", data); //free shit exit
	}
}
