/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:40 by dren              #+#    #+#             */
/*   Updated: 2024/05/22 18:16:29 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **st)
{
	t_stack	*temp;

	if (*st == NULL || (*st)->next == NULL)
		return ;
	temp = *st;
	while ((*st)->next->next != NULL)
		*st = (*st)->next;
	(*st)->next->next = temp;
	temp = (*st)->next;
	(*st)->next = NULL;
	*st = temp;
}

void	rra(t_stack **a, int *a_pos)
{
	ft_reverse(a);
	if (a_pos != NULL)
		++*a_pos;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int *b_pos)
{
	ft_reverse(b);
	if (b_pos != NULL)
		++*b_pos;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int *a_pos, int *b_pos)
{
	ft_reverse(a);
	ft_reverse(b);
	if (a_pos != NULL)
	{
		++*a_pos;
		++*b_pos;
	}
	write(1, "rrr\n", 4);
}

void	rrx(t_stack	**st, int *x_pos)
{
	if ((*st)->stack == 'a')
		rra(st, x_pos);
	else
		rrb(st, x_pos);
}
