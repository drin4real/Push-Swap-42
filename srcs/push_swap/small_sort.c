/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:28:48 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 18:18:07 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a)
{
	int	min;
	int	max;

	min = min_index(*a);
	max = max_index(*a);
	if ((*a)->index == max)
		ra(a, NULL);
	else if ((*a)->next->index == max)
		rra(a, NULL);
	if ((*a)->index != min)
		sa(a);
}
