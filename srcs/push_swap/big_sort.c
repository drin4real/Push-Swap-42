/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:00:06 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 18:15:44 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calcul_moves_number(int *a, int *b, int a_size, int b_size)
{
	int	moves;

	moves = 0;
	if (*a <= (a_size + 1) / 2 && *b <= (b_size + 1) / 2)
		moves = ft_max(*a, *b) + 1;
	else if (*a <= (a_size + 1) / 2 && *b > (b_size + 1) / 2)
	{
		moves = *a + (b_size - *b + 1);
		ft_negative(1, b, b_size);
	}
	else if (*a > (a_size + 1) / 2 && *b <= (b_size + 1) / 2)
	{
		moves = *b + (a_size - *a + 1);
		ft_negative(1, a, a_size);
	}
	else if (*a > (a_size + 1) / 2 && *b > (b_size + 1) / 2)
	{
		moves = ft_max((b_size - *b + 1), (a_size - *a + 1)) + 1;
		ft_negative(2, a, a_size, b, b_size);
	}
	return (moves);
}

static t_targets	cheapest_move(t_stack *from, t_stack *to, int a, int b)
{
	t_targets	best;
	t_targets	temp;
	int			target;
	int			i;

	i = 0;
	best.moves = 0;
	target = -1;
	while (best.moves != 1 && from != NULL)
	{
		if (is_extremum(from->index, to))
		{
			target = best_index(to);
			temp.target = find_index(to, target);
		}
		else
			temp.target = find_target(from->index, to);
		temp.arrow = i++;
		temp.moves = calcul_moves_number(&temp.arrow, &temp.target, a, b);
		if (best.moves == 0 || temp.moves < best.moves)
			best = temp;
		from = from->next;
	}
	return (best);
}

static void	insert(t_stack **from, t_stack **to, int arrowstack_size, int stop)
{
	t_targets	tar;
	int			targetstack_size;

	targetstack_size = ft_stsize(*to);
	while (!(stop == 3 && check_order(*from)) && arrowstack_size > stop)
	{
		tar = cheapest_move(*from, *to, arrowstack_size, targetstack_size);
		while (tar.arrow > 0 && tar.target > 0)
			rr(from, to, &tar.arrow, &tar.target);
		while (tar.arrow < 0 && tar.target < 0)
			rrr(from, to, &tar.arrow, &tar.target);
		while (tar.arrow > 0)
			rx(from, &tar.arrow);
		while (tar.target > 0)
			rx(to, &tar.target);
		while (tar.arrow < 0)
			rrx(from, &tar.arrow);
		while (tar.target < 0)
			rrx(to, &tar.target);
		px(from, to);
		--arrowstack_size;
		++targetstack_size;
	}
}

void	big_sort(t_stack **a, t_stack **b, int a_size)
{
	int			b_size;

	pb(a, b);
	pb(a, b);
	insert(a, b, a_size, 3);
	a_size = ft_stsize(*a);
	if (a_size == 3)
		small_sort(a);
	b_size = ft_stsize(*b);
	insert(b, a, b_size, 0);
}
