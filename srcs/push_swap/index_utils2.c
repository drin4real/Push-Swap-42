/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:57:35 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 18:16:11 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_extremum(int index, t_stack *b)
{
	if (index > max_index(b) || index < min_index(b))
		return (1);
	return (0);
}

int	best_index(t_stack *st)
{
	if (st->stack == 'a')
		return (min_index(st));
	return (max_index(st));
}

int	max_index(t_stack *st)
{
	int	max;

	max = 0;
	while (st != NULL)
	{
		if (st->index > max)
			max = st->index;
		st = st->next;
	}
	return (max);
}

int	min_index(t_stack *st)
{
	int	min;

	min = -1;
	while (st != NULL)
	{
		if (min == -1 || st->index < min)
			min = st->index;
		st = st->next;
	}
	return (min);
}
