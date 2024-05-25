/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:54:49 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 17:09:53 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->stack = 'a';
	new->next = NULL;
	return (new);
}

void	ft_stadd_back(t_stack **st, t_stack *new)
{
	t_stack	*last;

	if (*st)
	{
		last = ft_stlast(*st);
		last->next = new;
	}
	else
		*st = new;
}

int	check_order(t_stack	*st)
{
	int	nb;

	while (st->next != NULL)
	{
		nb = st->content;
		st = st->next;
		if (nb > st->content)
			return (0);
	}
	return (1);
}

void	ft_stclear(t_stack **st)
{
	t_stack	*temp;

	if (!st)
		return ;
	while (*st != NULL)
	{
		temp = (*st)->next;
		free(*st);
		*st = temp;
	}
}
