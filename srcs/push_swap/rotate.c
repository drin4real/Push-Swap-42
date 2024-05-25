/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:27 by dren              #+#    #+#             */
/*   Updated: 2024/05/22 18:16:49 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **st)
{
	t_stack	*last;

	if (*st == NULL || (*st)->next == NULL)
		return ;
	last = ft_stlast(*st);
	last->next = *st;
	*st = (*st)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a, int *a_pos)
{
	ft_rotate(a);
	if (a_pos != NULL)
		--*a_pos;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b, int *b_pos)
{
	ft_rotate(b);
	if (b_pos != NULL)
		--*b_pos;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int *a_pos, int *b_pos)
{
	ft_rotate(a);
	ft_rotate(b);
	if (a_pos != NULL)
	{
		--(*a_pos);
		--(*b_pos);
	}
	write(1, "rr\n", 3);
}

void	rx(t_stack	**st, int *x_pos)
{
	if ((*st)->stack == 'a')
		ra(st, x_pos);
	else
		rb(st, x_pos);
}
