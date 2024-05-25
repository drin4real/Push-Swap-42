/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:29:33 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 18:28:08 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int size)
{
	int	min;

	if (check_order(*a))
		return ;
	if (size <= 3)
		small_sort(a);
	else
		big_sort(a, b, size - 2);
	min = find_index(*a, 0);
	if (min > (size + 1) / 2)
	{
		min = -(size - min);
		while (min < 0)
			rra(a, &min);
	}
	else
		while (min > 0)
			ra(a, &min);
}
