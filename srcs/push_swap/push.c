/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:13 by dren              #+#    #+#             */
/*   Updated: 2024/05/22 18:16:20 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = NULL;
	if (!*dest)
		*dest = *src;
	else
		ft_stadd_front(dest, *src);
	*src = temp;
}

void	pa(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	(*a)->stack = 'a';
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	(*b)->stack = 'b';
	write(1, "pb\n", 3);
}

void	px(t_stack **from, t_stack **to)
{
	if ((*from)->stack == 'a')
		pb(from, to);
	else
		pa(from, to);
}
