/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:35:32 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 18:18:55 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_stack *st, int nb)
{
	while (st != NULL)
	{
		if (st->content == nb)
			return (0);
		st = st->next;
	}
	return (1);
}

static int	is_valid_argument(t_stack *st, char *arg, long nb)
{
	int	i;

	i = 0;
	if (nb >= INT_MAX || nb <= INT_MIN)
		return (0);
	while (arg[i] == '+' || arg[i] == '-')
		++i;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		++i;
	}
	if (!check_doubles(st, (int)nb))
		return (0);
	return (1);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	stack_init(t_stack **a, char **argv, int argc)
{
	t_stack	*new_node;
	char	**temp;
	long	nb;
	int		i;
	int		j;

	i = 0;
	while (i++ < argc - 1)
	{
		j = 0;
		temp = NULL;
		temp = ft_split(argv[i], ' ');
		while (temp[j] != NULL)
		{
			nb = ft_atol(temp[j]);
			if (!is_valid_argument(*a, temp[j], nb))
				ft_free(a, NULL, temp, 1);
			new_node = ft_stnew((int)nb);
			if (!new_node)
				ft_free(a, NULL, temp, 1);
			ft_stadd_back(a, new_node);
			++j;
		}
		free_tab(temp);
	}
}
