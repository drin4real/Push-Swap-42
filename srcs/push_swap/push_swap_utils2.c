/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:03:16 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/20 23:00:12 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stadd_front(t_stack **st, t_stack *new)
{
	if (st && new)
	{
		new->next = *st;
		*st = new;
	}
}

t_stack	*ft_stlast(t_stack *st)
{
	if (st)
	{
		while (st->next != NULL)
			st = st->next;
	}
	return (st);
}

void	ft_stprint(t_stack *s)
{
	if (!s)
		ft_printf("Pile Vide\n");
	ft_printf("---\n");
	while (s != NULL)
	{
		ft_printf("%d : [%d]\n", s->index, s->content);
		s = s->next;
	}
}

int	ft_stsize(t_stack *st)
{
	int	res;

	res = 0;
	while (st != NULL)
	{
		st = st->next;
		res++;
	}
	return (res);
}

void	ft_free(t_stack **a, t_stack **b, char **tab, int flag)
{
	int	i;

	i = 0;
	ft_stclear(a);
	ft_stclear(b);
	if (tab != NULL)
	{
		while (tab[i] != NULL)
			free(tab[i++]);
		free(tab);
	}
	if (flag)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
