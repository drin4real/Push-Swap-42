/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:08:37 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/20 14:58:15 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack *st, int size)
{
	t_stack	*lil;
	t_stack	*temp;
	int		i;

	i = 0;
	temp = st;
	lil = NULL;
	while (i < size)
	{
		while (lil == NULL || lil->index != -1)
		{
			lil = st;
			st = st->next;
		}
		while (st != NULL)
		{
			if (st->index == -1 && st->content < lil->content)
				lil = st;
			st = st->next;
		}
		lil->index = i++;
		st = temp;
	}
}

int	find_index(t_stack *st, int index)
{
	int	i;

	i = 0;
	while (st != NULL)
	{
		if (st->index == index)
			return (i);
		st = st->next;
		++i;
	}
	return (-1);
}

int	find_target(int index, t_stack *st)
{
	int	target;

	target = -1;
	if (st->stack == 'b')
	{
		while (1)
		{
			target = find_index(st, --index);
			if (target != -1)
				return (target);
		}
	}
	else
	{
		while (1)
		{
			target = find_index(st, ++index);
			if (target != -1)
				return (target);
		}
	}
	return (-1);
}
